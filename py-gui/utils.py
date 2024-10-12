import pygame
from wrapper import pyboard

def get_square_under_mouse():
    from gui import SQUARE_SIZE
    mouse_x, mouse_y = pygame.mouse.get_pos()
    col = mouse_x // SQUARE_SIZE
    row = mouse_y // SQUARE_SIZE
    return row, col

def get_piece_at(row, col):
    return pyboard[row][col]  