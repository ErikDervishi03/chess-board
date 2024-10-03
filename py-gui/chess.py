import ctypes
import random

# Load the shared library
#chess_engine = ctypes.CDLL('./chess_engine.so')

# Bind C functions to Python functions
#chess_engine.initialize_board.restype = None
#chess_engine.make_move.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
#chess_engine.make_move.restype = ctypes.c_int

selected_piece = '.'

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
    print("Board initialized.")

def select_piece(piece):
    global selected_piece 
    selected_piece = piece
    display_moves(select_piece)

def make_move(move_from, move_to):
    local_piece = board[move_from[0]][move_from[1]]
    board[move_from[0]][move_from[1]] = '.'
    board[move_to[0]][move_to[1]] = local_piece

def display_moves(piece):
    #empty for now
    print(selected_piece)