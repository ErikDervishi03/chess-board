#ifndef __VALID_H__
#define __VALID_H__

#include "types.h"
#include "./data_structure/listc.h"
#include "board.h"

// idea create a bit mask in order to check wich error is active 

int isOutOfBounds( cell pos );

int isLegalMove ( BOARD board , move move_ , enum piece piece_ , cell currPos );

List * pawnLegalMoves ( BOARD board, cell currPos );

List * knightLegalMoves ( BOARD board , cell currPos );

List * bishopLegalMoves ( BOARD board , cell currPos );

List * rookLegalMoves ( BOARD board, cell currPos );

List * queenLegalMoves (BOARD board, cell currPos );

List * kingLegalMoves ( BOARD board, cell currPos );

int isInCheck();

#endif // __VALID_H__