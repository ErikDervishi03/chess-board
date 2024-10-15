import random
from wrapper import pyboard, do_move_w
from utils import get_piece_at

selected_piece_pos = (-1, -1)

# We print row first, then column. Rows and columns are 0-indexed, so top left is 0-0, bottom right is 7-7. Top is white, bottom is black

def select_piece(row, col):
    print("\nIn select_piece")
    from gui import display_moves
    global selected_piece_pos 
    selected_piece_pos = (row, col)
    display_moves(selected_piece_pos[0], selected_piece_pos[1])

def make_move(move_from, move_to):
    do_move_w(pyboard, move_from, move_to) # execute on c before modifying pyboard
    local_piece = pyboard[move_from[0]][move_from[1]]
    pyboard[move_from[0]][move_from[1]] = '.'
    pyboard[move_to[0]][move_to[1]] = local_piece

def get_selected_piece():
    return selected_piece_pos