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

BOARD global_board;

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

        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        global_board[i][j] = boardArray[(i*COLUMNS) + j];

                }

        }
}

void do_move ( BoardReceiver boardArray , move from, move to ){

        BOARD board;
        convert_board(boardArray);

        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        board[i][j] = global_board[i][j];

                }

        }

        if( !isOutOfBounds( to ) ){

                board[to.r][to.c] = board[from.r][from.c];

                board[from.r][from.c] = EMPTY;

        }
        
        printb(board);
}

void printb (BOARD board) {
        FILE *f = fopen("../boardLog.txt", "w");//deletes old content
        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        if(board[i][j] == EMPTY){
                                fprintf(f, "0 ");
                        }else{
                                switch(board[i][j]){
                                        case B_PAWN:
                                                fprintf(f, "p ");
                                                break;
                                        case B_KNIGHT:
                                                fprintf(f, "n ");
                                                break;
                                        case B_BISHOP:
                                                fprintf(f, "b ");
                                                break;
                                        case B_ROOK:
                                                fprintf(f, "r ");
                                                break;
                                        case B_QUEEN:
                                                fprintf(f, "q ");
                                                break; 
                                        case B_KING:
                                                fprintf(f, "k ");
                                                break;  
                                        case W_PAWN:
                                                fprintf(f, "P ");
                                                break; 
                                        case W_KNIGHT:
                                                fprintf(f, "N ");
                                                break;
                                        case W_BISHOP:
                                                fprintf(f, "B ");
                                                break;
                                        case W_ROOK:
                                                fprintf(f, "R ");
                                                break;  
                                        case W_QUEEN:
                                                fprintf(f, "Q ");
                                                break; 
                                        case W_KING:
                                                fprintf(f, "K ");
                                                break;  
                                        default:
                                                fprintf(f, "X ");
                                }
                        }

                }
                fprintf(f, "\n");

        }
        fclose(f);
} 

