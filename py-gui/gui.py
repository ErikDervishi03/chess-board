import pygame
from chess import initialize_board, make_move, get_piece_at
from utils import get_square_under_mouse

# Initialize Pygame and the mock chess engine
pygame.init()
initialize_board()

# Define board parameters
WIDTH, HEIGHT = 640, 640
SQUARE_SIZE = WIDTH // 8
PADDING = SQUARE_SIZE / 8
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Chess Board")

# Define colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Define Assets
board_image = pygame.image.load('assets/board.png')
board_image = pygame.transform.scale(board_image, (WIDTH, HEIGHT))
piece_images = {
    'P': pygame.image.load('assets/wPawn.png'),
    'p': pygame.image.load('assets/bPawn.png'),
    'R': pygame.image.load('assets/wRook.png'),
    'r': pygame.image.load('assets/bRook.png'),
    'K': pygame.image.load('assets/wKing.png'),
    'k': pygame.image.load('assets/bKing.png'),
    'Q': pygame.image.load('assets/wQueen.png'),
    'q': pygame.image.load('assets/bQueen.png'),
    'B': pygame.image.load('assets/wBishop.png'),
    'b': pygame.image.load('assets/bBishop.png'),
    'N': pygame.image.load('assets/wKnight.png'),
    'n': pygame.image.load('assets/bKnight.png'),
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
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                row, col = get_square_under_mouse()
                print(f"Clicked on square: {row}, {col}")
                # Test moving from and to clicked squares (random for now)
                make_move(f"{row}{col}", f"{(row+1)%8}{(col+1)%8}")

        # Draw the chessboard image
        screen.blit(board_image, (0, 0))

        # Draw the pieces on top of the board
        draw_pieces()

        pygame.display.flip()

    pygame.quit()