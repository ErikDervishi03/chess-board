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
        move enPass;
        enPass.r = -1;
        enPass.c = -1;

        for (int i = 0; i < ROWS; i++){

                for (int j = 0; j < COLUMNS; j++){

                        board[i][j] = global_board[i][j];

                        if(board[i][j] == W_EN_PASSANT || board[i][j] == B_EN_PASSANT){ enPass.r = i; enPass.c = j;}

                }

        }

        if( !isOutOfBounds( to ) ){

                board[to.r][to.c] = board[from.r][from.c];//Make the move
                board[from.r][from.c] = EMPTY; 

                if(enPass.r != -1 && enPass.c != -1){

                        if(to.r == enPass.r && to.c == enPass.c){ //Delete taken pawn if move takes en passant
                        
                                if(to.r == 2){ board[3][from.c] = EMPTY; }
                                if(to.r == 5){ board[4][from.c] = EMPTY; }

                        }

                        if(board[enPass.r][enPass.c] == W_EN_PASSANT || board[enPass.r][enPass.c] == B_EN_PASSANT){//Remove expired en passant targets
                                board[enPass.r][enPass.c] = EMPTY;
                        }

                }

                if(board[to.r][to.c] == B_PAWN || board[to.r][to.c] == W_PAWN){ //Create En Passant target if move is a pawn double-step

                        if(from.r == 1 && to.r == 3){ board[2][from.c] = W_EN_PASSANT; }
                        if(from.r == 6 && to.r == 4){ board[5][from.c] = B_EN_PASSANT; }

                }

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
                                        case B_EN_PASSANT:
                                                fprintf(f, "e ");
                                                break;
                                        case W_EN_PASSANT:
                                                fprintf(f, "E ");
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

