import ctypes
import random

# Load the shared library
#chess_engine = ctypes.CDLL('./chess_engine.so')

# Bind C functions to Python functions
#chess_engine.initialize_board.restype = None
#chess_engine.make_move.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
#chess_engine.make_move.restype = ctypes.c_int

# Mock data for the board (8x8 grid)
board = [
    ['R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'],
    ['P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'],
    ['.', '.', '.', '.', '.', '.', '.', '.'],
    ['.', '.', '.', '.', '.', '.', '.', '.'],
    ['.', '.', '.', '.', '.', '.', '.', '.'],
    ['.', '.', '.', '.', '.', '.', '.', '.'],
    ['p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'],
    ['r', 'n', 'b', 'q', 'k', 'b', 'n', 'r']
    
]

def initialize_board():
    """Mock function to initialize the board."""
    print("Board initialized.")

def make_move(move_from, move_to):
    """Mock function to simulate making a move."""
    print(f"Moving piece from {move_from} to {move_to}")
    # For testing purposes, randomly move a piece or make no change
    return random.choice([0, 1])  # Simulate a legal (1) or illegal (0) move

def get_piece_at(row, col):
    """Return the piece at the given position (mocked)."""
    return board[row][col]  # Returns a piece symbol or '.' for empty
