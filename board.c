#include "board.h"
#include "types.h"
#include <stdio.h>

const BOARD DEFAULT_BOARD = {

        {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK},
        {WHITE_PAWN, WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN,  WHITE_PAWN, WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN},
        {FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL,   FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL},
        {FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL,   FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL},
        {FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL,   FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL},
        {FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL,   FREE_CELL,  FREE_CELL,    FREE_CELL,    FREE_CELL},
        {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK},
        {BLACK_PAWN, BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN,  BLACK_PAWN, BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN}

};

boardInfo extractBoardInfo ( BOARD board ){

        boardInfo * info = (boardInfo *) malloc(sizeof(boardInfo));

        info->whitePieces = create_list();
        info->blackPieces = create_list();
        init_stack(info->moves);

        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        if (board[i][j].pcolor == white){

                                add_to_list( info->whitePieces , &board[i][j] );

                        }else if (board[i][j].pcolor == black){

                                add_to_list( info->blackPieces , &board[i][j] );

                        }

                }

        }

        init_stack ( info->moves );

        return *info;

}

void do_move ( BOARD board , move move_ ){

        if( isLegalMove( board , move_ ) ){

                board[move_.r][move_.c] = board[move_.r][move_.c];

                board[move_.r][move_.c] = FREE_CELL;

        }

}

void printb (BOARD board) {
        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        printf("%d ", board[i][j].ptype);

                }
                printf("\n");

        }
} 

