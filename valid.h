#ifndef __VALID_H__
#define __VALID_H__

#include "data_structure/listc.h"
#include "types.h"

// idea create a bit mask in order to check wich error is active 

int pieceCMP ( piece piece1, piece piece2 );

int isOutOfBounds( cell pos );

int isLegalMove ( BOARD board , move move_);

List * pawnLegalMoves ( BOARD board, cell currPos );

List * knightLegalMoves ( BOARD board , cell currPos );

List * bishopLegalMoves ( BOARD board , cell currPos );

List * rookLegalMoves ( BOARD board, cell currPos );

List * queenLegalMoves (BOARD board, cell currPos );

#endif // __VALID_H__