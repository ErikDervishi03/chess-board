#include "board.h"

const BOARD DEFAULT_BOARD = {

        {W_ROOK, W_KNIGHT, W_BISHOP, W_KING, W_QUEEN, W_BISHOP, W_KNIGHT, W_ROOK},
        {W_PAWN, W_PAWN,   W_PAWN,   W_PAWN,  W_PAWN, W_PAWN,   W_PAWN,   W_PAWN},
        {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
        {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
        {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
        {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
        {B_PAWN, B_PAWN,   B_PAWN,   B_PAWN,  B_PAWN, B_PAWN,   B_PAWN,   B_PAWN},
        {B_ROOK, B_KNIGHT, B_BISHOP, B_KING, B_QUEEN, B_BISHOP, B_KNIGHT, B_ROOK}
        

};

BOARD* global_board[ROWS][COLUMNS];

boardInfo extractBoardInfo ( BOARD board ){

        boardInfo * info = (boardInfo *) malloc(sizeof(boardInfo));

        info->whitePieces = create_list();
        info->blackPieces = create_list();
        init_stack(info->moves);

        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        if (isWhite(board[i][j])){

                                add_to_list( info->whitePieces , &board[i][j] );

                        }else if (isBlack(board[i][j])){

                                add_to_list( info->blackPieces , &board[i][j] );

                        }

                }

        }

        init_stack ( info->moves );

        return *info;

}

void convert_board( BoardReceiver boardArray ){

        BOARD board;
        INIT_BOARD(board);

        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        board[i][j] = boardArray[(i*COLUMNS) + j];

                }

        }
}

void do_move ( BoardReceiver boardArray , move from, move to ){

        convert_board(boardArray);

        BOARD board;
        INIT_BOARD(board);
        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        board[i][j] = (long int)global_board[(i*COLUMNS) + j];

                }

        }

        if( !isOutOfBounds( to ) ){

                board[to.r][to.c] = board[from.r][from.c];

                board[from.r][from.c] = EMPTY;

        }
        //logfile?
}

void printb (BOARD board) {
        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        if(board[i][j] == EMPTY){
                                printf("0 ");
                        }else{
                                printf("%d ", board[i][j]);
                        }
                }
                printf("\n");

        }
} 

