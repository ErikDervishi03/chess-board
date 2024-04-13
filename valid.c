#include "valid.h"
#include "data_structure/listc.h"
#include "types.h"


#define areOppositeColor(color1, color2) \
        ((color1 == white && color2 == black) || \
        (color1 == black && color2 == white))


int pieceCMP ( piece piece1, piece piece2 ){
    return ((piece1.pcolor == piece2.pcolor) && (piece1.ptype == piece2.ptype));
}

int isOutOfBounds(cell pos) {
    return (pos.r < 0 || pos.r >= ROWS || pos.c < 0 || pos.c >= COLUMNS);
}

int isLegalMove ( BOARD board , move move_) {

    return !isOutOfBounds(move_) ;
}

List * pawnLegalMoves (BOARD board, cell currPos) {
    piece currPawn = board[currPos.r][currPos.c];
    List * legalMoves = create_list();
    int inc = (currPawn.pcolor == white) ? 1 : -1;

    // 1 square ahead move
    if (!isOutOfBounds((move){currPos.r + inc, currPos.c}) &&
        pieceCMP(board[currPos.r + inc][currPos.c], FREE_CELL)) {
        move* new_move = malloc(sizeof(move));
        if (new_move) {
            new_move->r = currPos.r + inc;
            new_move->c = currPos.c;
            add_to_list(legalMoves, new_move);
        }
    }

    // 2 squares ahead in the first move
    int pawnInitialRow = (currPawn.pcolor == white) ? WHITE_PAWN_INITIAL_ROW : BLACK_PAWN_INITIAL_ROW;
    if (currPos.r == pawnInitialRow && pieceCMP(board[currPos.r + 2 * inc][currPos.c], FREE_CELL)) {
        move* new_move = malloc(sizeof(move));
        if (new_move) {
            new_move->r = currPos.r + 2 * inc;
            new_move->c = currPos.c;
            add_to_list(legalMoves, new_move);
        }
    }

    // Left diagonal eat
    if (!isOutOfBounds((move){currPos.r + inc, currPos.c - 1}) &&
        areOppositeColor(board[currPos.r + inc][currPos.c - 1].pcolor, currPawn.pcolor)) {
        move* new_move = malloc(sizeof(move));
        if (new_move) {
            new_move->r = currPos.r + inc;
            new_move->c = currPos.c - 1;
            add_to_list(legalMoves, new_move);
        }
    }

    // Right diagonal eat
    if (!isOutOfBounds((move){currPos.r + inc, currPos.c + 1}) &&
        areOppositeColor(board[currPos.r + inc][currPos.c + 1].pcolor, currPawn.pcolor)) {
        move* new_move = malloc(sizeof(move));
        if (new_move) {
            new_move->r = currPos.r + inc;
            new_move->c = currPos.c + 1;
            add_to_list(legalMoves, new_move);
        }
    }

    return legalMoves;
}
