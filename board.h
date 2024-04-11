#ifndef __TABLE_H__
#define __TABLE_H__

#include "types.h"
#include <string.h>

/*

        TO DO: 
                move (BOARD, PIECE, POSITION)

        move --> piece move from a loc to another loc.

*/


#define INIT_BOARD(board) memcpy(board, DEFAULT_BOARD, sizeof(BOARD))

const BOARD DEFAULT_BOARD = {
        {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK},
        {BLACK_PAWN, BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN,  BLACK_PAWN, BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN},
        {FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL,   FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL},
        {FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL,   FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL},
        {FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL,   FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL},
        {FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL,   FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL},
        {WHITE_PAWN, WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN,  WHITE_PAWN, WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN},
        {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK}
};

int isLegalMove( BOARD * board , move move_ ){
        return true;
}

void do_move ( BOARD * board , move move_ ){

        if( isLegalMove( board , move_ ) ){

                memcpy(&board[move_.from.r][move_.from.c], &FREE_CELL, sizeof(piece));

        }

}


#endif