#ifndef __VALID_H__
#define __VALID_H__

#include "types.h"

// idea create a bit mask in order to check wich error is active 

int isLegalMove ( BOARD * board , move move_) {

    return !isOutOfBounds(move_.to.r, move_.to.c) ;
}

int isOutOfBounds(int row, int col) {
    return (row < 0 || row >= ROWS || col < 0 || col >= COLUMNS);
}

#endif // __VALID_H__