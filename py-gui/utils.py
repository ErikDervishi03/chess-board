import pygame

def get_square_under_mouse():
    mouse_x, mouse_y = pygame.mouse.get_pos()
    col = mouse_x # SQUARE_SIZE
    row = mouse_y # SQUARE_SIZE
    return row, col
