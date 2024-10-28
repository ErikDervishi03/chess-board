import pygame
from chess import make_move, select_piece, get_selected_piece
from utils import get_square_under_mouse, get_piece_at
from wrapper import legal_moves_w, pyboard, List, Node, Cell, ArrayStruct, reset_boards

# Initialize Pygame
pygame.init()

# Define board parameters
WIDTH, HEIGHT = 800, 640
SQUARE_SIZE = WIDTH // 10 # Extra space is 2 squares wide
PADDING = SQUARE_SIZE / 32 # seems useless but looks bad without this
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Chess Board")
pygame.font.init()
my_font = pygame.freetype.Font(None, 20)
legal_moves = ()
b_moves = False
flipped = False # Black POV
turn = 'White'

# Define colors (blue theme)
WHITE = (105, 113, 129)
BLACK = (39, 45, 56)
BUTTON = (255, 255, 255)

# Define Assets
piece_STDSIZE = (75 , 75)
piece_images = {
    'P': pygame.transform.scale(pygame.image.load('assets/wPawn.png'), piece_STDSIZE),
    'p': pygame.transform.scale(pygame.image.load('assets/bPawn.png'), piece_STDSIZE),
    'R': pygame.transform.scale(pygame.image.load('assets/wRook.png'), piece_STDSIZE),
    'r': pygame.transform.scale(pygame.image.load('assets/bRook.png'), piece_STDSIZE),
    'K': pygame.transform.scale(pygame.image.load('assets/wKing.png'), piece_STDSIZE),
    'k': pygame.transform.scale(pygame.image.load('assets/bKing.png'), piece_STDSIZE),
    'Q': pygame.transform.scale(pygame.image.load('assets/wQueen.png'), piece_STDSIZE),
    'q': pygame.transform.scale(pygame.image.load('assets/bQueen.png'), piece_STDSIZE),
    'B': pygame.transform.scale(pygame.image.load('assets/wBishop.png'), piece_STDSIZE),
    'b': pygame.transform.scale(pygame.image.load('assets/bBishop.png'), piece_STDSIZE),
    'N': pygame.transform.scale(pygame.image.load('assets/wKnight.png'), piece_STDSIZE),
    'n': pygame.transform.scale(pygame.image.load('assets/bKnight.png'), piece_STDSIZE)
}

def empty_moves():
    global legal_moves
    global b_moves
    for move in legal_moves:
        move.r = -1
        move.c = -1
    b_moves = False

def flip_board():
    global flipped
    flipped = not flipped

def change_turn():
    global turn
    if turn == 'White':
        turn = 'Black'
    else:
        turn = 'White'

def is_turn(piece):
    if not piece:
        return False 
    if turn == "White":
        return piece.isupper()
    elif turn == "Black":
        return piece.islower()

def draw_buttons():
    """Draw the buttons to the side of the screen."""
    pygame.draw.rect(screen, BUTTON, (8.5 * SQUARE_SIZE, 0.25 * SQUARE_SIZE, SQUARE_SIZE, 0.5 * SQUARE_SIZE))
    my_font.render_to(screen, (8.6 * SQUARE_SIZE, 0.4 * SQUARE_SIZE), "Reset", (0, 0, 0))

    pygame.draw.rect(screen, BUTTON, (8.5 * SQUARE_SIZE, 1.25 * SQUARE_SIZE, SQUARE_SIZE, 0.5 * SQUARE_SIZE))
    my_font.render_to(screen, (8.6 * SQUARE_SIZE, 1.4 * SQUARE_SIZE), "Flip", (0, 0, 0))

    pygame.draw.rect(screen, (0,0,0), (8.6 * SQUARE_SIZE, 2.4 * SQUARE_SIZE, SQUARE_SIZE, 0.5 * SQUARE_SIZE))
    my_font.render_to(screen, (8.6 * SQUARE_SIZE, 2.4 * SQUARE_SIZE), turn, (255, 255, 255))


def draw_board():
    """Draw the chessboard with alternating black and white squares."""
    global flipped
    for row in range(8):
        for col in range(8):
            if (row + col) % 2 == 0:
                if(flipped):
                    color = WHITE
                else:
                    color = BLACK
            else:
                if(flipped):
                    color = BLACK
                else:
                    color = WHITE
            pygame.draw.rect(screen, color, (col * SQUARE_SIZE, row * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE))

def draw_pieces():
    """Draw the pieces."""
    for row in range(8):
        for col in range(8):
            piece = get_piece_at(row, col)
            row_l, col_l = row, col
            if flipped:
                row_l = 7 - row
            if piece is not None and piece != '.':  
                screen.blit(piece_images[piece], ((col_l * SQUARE_SIZE)+PADDING, (row_l * SQUARE_SIZE)+PADDING))

def display_moves(row, col):
    print("\nIn display_moves for loc "+str(row)+" "+str(col))
    """Draw the legal moves for a clicked piece"""
    global legal_moves
    global b_moves
    legal_moves = legal_moves_w(pyboard, (row,col)).arr
    b_moves = True
    
def draw_moves():
    global legal_moves
    global b_moves
    if b_moves == False:
        return
    #print("made it past first if in draw_moves, this is b_moves: "+str(b_moves))
    for move in legal_moves:
        row = move.r
        col = move.c
        if row == -1:
            continue
        piece = pyboard[row][col]

        row_l, col_l = row, col
        if flipped:
            row_l = 7 - row
        
        # Determine circle size based on if it's an enemy piece
        if piece == '.':
            # Draw small transparent circle for an empty square
            pygame.draw.circle(screen, (255,255,255), 
                               (col_l * SQUARE_SIZE + SQUARE_SIZE // 2, row_l * SQUARE_SIZE + SQUARE_SIZE // 2), 
                               SQUARE_SIZE // 5)
        else:
            # Draw a larger red circle for an enemy piece
            pygame.draw.circle(screen, (255,255,255), 
                               (col_l * SQUARE_SIZE + SQUARE_SIZE // 2, row_l * SQUARE_SIZE + SQUARE_SIZE // 2), 
                               SQUARE_SIZE // 2)


def run_game():
    running = True
    dragging = False
    global legal_moves
    global b_moves
    global turn
    pygame.mouse.set_cursor(pygame.SYSTEM_CURSOR_ARROW)
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            
            if event.type == pygame.MOUSEBUTTONDOWN:
                pygame.mouse.set_cursor(pygame.SYSTEM_CURSOR_HAND)
                row, col = get_square_under_mouse()
                if (row == -1) and (col == -1):
                    reset_boards()
                    turn = 'White'
                if (row == -2) and (col == -2):
                    flip_board()
                else:
                    piece = get_piece_at(row, col)
                    move_from = get_selected_piece()
                    if piece != '.':
                        if not is_turn(piece):
                            if make_move(move_from, (row,col)):
                                change_turn()
                            empty_moves()
                            continue
                        print("Grabbed valid piece")
                        dragging = True
                        select_piece(row, col)
                    else:
                        print("here")
                        if make_move(move_from, (row,col)):
                            change_turn()
                        empty_moves()
            
            if event.type == pygame.MOUSEBUTTONUP:
                pygame.mouse.set_cursor(pygame.SYSTEM_CURSOR_ARROW)
                if dragging == True:
                    dragging = False
                    if (row, col) == get_square_under_mouse():
                        print("did not move piece")
                        #reset image to square if dragging(might not be necessary)
                        continue
                    row, col = get_square_under_mouse()
                    move_from = get_selected_piece()
                    make_move(move_from, (row, col))
                    change_turn()
                    empty_moves()

        draw_buttons()

        # Draw the chessboard image
        draw_board()
        
        # Draw the pieces on top of the board
        draw_pieces()

        draw_moves()

        pygame.display.flip()

    pygame.quit()