import ctypes
import random

# Load the shared library
#chess_engine = ctypes.CDLL('./chess_engine.so')

# Bind C functions to Python functions
#chess_engine.initialize_board.restype = None
#chess_engine.make_move.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
#chess_engine.make_move.restype = ctypes.c_int

selected_piece_pos = (-1, -1)

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
] # We print row first, then column. Rows and columns are 0-indexed, so top left is 0-0, bottom right is 7-7

def initialize_board():
    print("Board initialized.")

def select_piece(row, col):
    global selected_piece_pos 
    selected_piece_pos = (row, col)
    display_moves(selected_piece_pos)

def make_move(move_from, move_to):
    local_piece = board[move_from[0]][move_from[1]]
    board[move_from[0]][move_from[1]] = '.'
    board[move_to[0]][move_to[1]] = local_piece

def display_moves(piece):
    #empty for now
    return 0

def get_selected_piece():
    return selected_piece_pos