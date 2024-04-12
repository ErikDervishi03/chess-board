#ifndef __VALID_H__
#define __VALID_H__

#include "types.h"

// idea create a bit mask in order to check wich error is active 

int pieceCMP ( piece piece1, piece piece2 );

int isOutOfBounds( cell pos );

int isLegalMove ( BOARD board , move move_);

mlist * pawnLegalMoves ( BOARD board, cell currPos );

#endif // __VALID_H__