#ifndef __BOARD_H__
#define __BOARD_H__

#include "string.h"
#include "./types.h"
#include "./valid.h"
#include "./data_structure/stack.h"
#include <stdio.h>

#define INIT_BOARD(board) memcpy(board, DEFAULT_BOARD, sizeof(BOARD))
#define isBlack(_piece) (_piece>=0 && _piece<=5)
#define isWhite(_piece) (_piece>=6 && _piece<=11)

extern const BOARD DEFAULT_BOARD ;

boardInfo extractBoardInfo ( BOARD board );

void convert_board( BoardReceiver boardArray );

void do_move ( BoardReceiver boardArray , move from, move to );

void printb (BOARD board);


#endif