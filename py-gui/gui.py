import pygame
from chess import initialize_board, make_move, select_piece, get_selected_piece
from utils import get_square_under_mouse, get_piece_at

# Initialize Pygame and the mock chess engine
pygame.init()
initialize_board()

# Define board parameters
WIDTH, HEIGHT = 640, 640
SQUARE_SIZE = WIDTH // 8
PADDING = SQUARE_SIZE / 32 # seems useless but looks bad without this
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Chess Board")

# Define colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Define Assets
board_image = pygame.image.load('assets/board.png')
board_image = pygame.transform.scale(board_image, (WIDTH, HEIGHT))
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

def draw_pieces():
    """Draw the pieces."""
    for row in range(8):
        for col in range(8):
            piece = get_piece_at(row, col)
            if piece != '.':  
                screen.blit(piece_images[piece], ((col * SQUARE_SIZE)+PADDING, (row * SQUARE_SIZE)+PADDING))

def run_game():
    running = True
    holdingM1 = False
    dragging = False
    pygame.mouse.set_cursor(pygame.SYSTEM_CURSOR_ARROW)
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            
            if event.type == pygame.MOUSEBUTTONDOWN:
                holdingM1 = True
                pygame.mouse.set_cursor(pygame.SYSTEM_CURSOR_HAND)
                row, col = get_square_under_mouse()
                print("The function get_square_under_mouse returns row "+str(row)+" and col "+str(col))
                piece = get_piece_at(row, col)
                if piece != '.':
                    dragging = True
                    select_piece(row, col)
            
            if event.type == pygame.MOUSEBUTTONUP:
                pygame.mouse.set_cursor(pygame.SYSTEM_CURSOR_ARROW)
                holdingM1 = False
                if dragging == True:
                    dragging = False
                    row, col = get_square_under_mouse()
                    #check for legal move
                    move_from = get_selected_piece()
                    make_move(move_from, (row, col))
                    print("Moved piece from"+str(move_from)+" to "+str(row)+", "+str(col))

        # Draw the chessboard image
        screen.blit(board_image, (0, 0))

        # Draw the pieces on top of the board
        draw_pieces()

        pygame.display.flip()

    pygame.quit()