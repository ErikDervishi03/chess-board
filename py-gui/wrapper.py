# This file interfaces with the c engine. It defines types we need for calling c functions

import ctypes 
from enum import Enum

ROWS = 8
COLUMNS = 8
BOARD_SIZE = ROWS * COLUMNS

PAWN = 1
BISHOP = 3
KNIGHT = 3
ROOK = 5
QUEEN = 9

WHITE_PAWN_INITIAL_ROW = 1
BLACK_PAWN_INITIAL_ROW = 6

B_PAWN = 0
B_KNIGHT = 1
B_BISHOP = 2
B_ROOK = 3
B_QUEEN = 4
B_KING = 5
W_PAWN = 6
W_KNIGHT = 7
W_BISHOP = 8
W_ROOK = 9
W_QUEEN = 10
W_KING = 11
EMPTY = 12

class Cell(ctypes.Structure):
    _fields_ = [("r", ctypes.c_int), ("c", ctypes.c_int)]

    @staticmethod
    def from_param(obj):
        # Check if obj is already a Cell instance, otherwise raise an error
        if isinstance(obj, Cell):
            return obj
        elif isinstance(obj, tuple) and len(obj) == 2:
            # Allow passing (row, col) as a tuple to automatically convert it
            return Cell(obj[0], obj[1])
        else:
            raise TypeError(f"Cannot convert {obj} to Cell")

class List:
    def __init__(self):
        self.size = 0
        self.head = None

class BoardInfo:
    def __init__(self):
        self.whitePieces = List()
        self.blackPieces = List()
        self.moves = List()  # List for moves

BoardType = ctypes.c_int * BOARD_SIZE

cBoard = BoardType(
    W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK,
    W_PAWN, W_PAWN,   W_PAWN,   W_PAWN,  W_PAWN, W_PAWN,   W_PAWN,   W_PAWN,
    EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY,
    EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY,
    EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY,
    EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY,
    B_PAWN, B_PAWN,   B_PAWN,   B_PAWN,  B_PAWN, B_PAWN,   B_PAWN,   B_PAWN,
    B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK
)

pyboard = [
    ['R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'],
    ['P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'],
    ['.', '.', '.', '.', '.', '.', '.', '.'],
    ['.', '.', '.', '.', '.', '.', '.', '.'],
    ['.', '.', '.', '.', '.', '.', '.', '.'],
    ['.', '.', '.', '.', '.', '.', '.', '.'],
    ['p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'],
    ['r', 'n', 'b', 'q', 'k', 'b', 'n', 'r']
] # We print row first, then column. Rows and columns are 0-indexed, so top left is 0-0, bottom right is 7-7. Upper case is white.

# We use pyboard for python stuff and then sync cboard to it for c correspondence
def sync_boards():
    piece_map = {
        'R': W_ROOK,    'N': W_KNIGHT, 'B': W_BISHOP,
        'Q': W_QUEEN,   'K': W_KING,   'P': W_PAWN,
        'r': B_ROOK,    'n': B_KNIGHT, 'b': B_BISHOP,
        'q': B_QUEEN,   'k': B_KING,   'p': B_PAWN,
        '.': EMPTY
    }

    for row in range(ROWS):
        for col in range(COLUMNS):
            piece_char = pyboard[row][col]
            cBoard[(row*COLUMNS) +col] = ctypes.c_int(piece_map[piece_char])


# Load the shared library
chess_engine = ctypes.CDLL('../sharedC.so')

# Bind C functions to Python functions
#chess_engine.initialize_board.restype = None
chess_engine.do_move.argtypes = [BoardType, Cell, Cell]
chess_engine.do_move.restype = None

# do_move wrapper so i can sync the boards
def do_move_w(pyboard, move_from, move_to):
    sync_boards()
    chess_engine.do_move(cBoard, move_from, move_to)




