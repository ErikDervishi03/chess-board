#include "valid.h"

int isOutOfBounds(int row, int col) {
    return (row < 0 || row >= ROWS || col < 0 || col >= COLUMNS);
}

int isLegalMove ( BOARD board , move move_) {

    return !isOutOfBounds(move_.to.r, move_.to.c) ;
}