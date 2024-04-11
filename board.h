#ifndef __TABLE_H__
#define __TABLE_H__

#include "string.h"
#include "./types.h"
#include "./valid.h"

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

boardInfo extractBoardInfo ( BOARD * board ){

        boardInfo * info = (boardInfo *) malloc(sizeof(boardInfo));

        info->whitePieces = create_list();
        info->blackPieces = create_list();
        init_stack(info->moves);

        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        if (board[i][j]->pcolor == white){

                                add_to_list( info->whitePieces , &board[i][j] );

                        }else if (board[i][j]->pcolor == black){

                                add_to_list( info->blackPieces , &board[i][j] );

                        }

                }

        }

        init_stack ( info->moves );

        return *info;

}


void do_move ( BOARD * board , move move_ ){

        if( isLegalMove( board , move_ ) ){

                memcpy(&board[move_.from.r][move_.from.c], &FREE_CELL, sizeof(piece));

                memcpy(&board[move_.to.r][move_.to.c], &move_.mpiece, sizeof(piece));

        }

}




#endif