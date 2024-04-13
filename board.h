#ifndef __BOARD_H__
#define __BOARD_H__

#include "string.h"
#include "./types.h"
#include "./valid.h"
#include <stdio.h>

/*

        TO DO: 
                move (BOARD, PIECE, POSITION)

        move --> piece move from a loc to another loc.

*/


#define INIT_BOARD(board) memcpy(board, DEFAULT_BOARD, sizeof(BOARD))

extern const BOARD DEFAULT_BOARD ;

boardInfo extractBoardInfo ( BOARD board );

void do_move ( BOARD board , move from, move to );

void printb (BOARD board);


#endif