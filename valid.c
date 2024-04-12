#include "valid.h"
#include "data_structure/listc.h"
#include "types.h"

int pieceCMP ( piece piece1, piece piece2 ){
    return ((piece1.pcolor == piece2.pcolor) && (piece1.ptype == piece2.ptype));
}

int isOutOfBounds(cell pos) {
    return (pos.r < 0 || pos.r >= ROWS || pos.c < 0 || pos.c >= COLUMNS);
}

int isLegalMove ( BOARD board , move move_) {

    return !isOutOfBounds(move_) ;
}

mlist * pawnLegalMoves ( BOARD board, cell currPos ) {

    piece currPawn = board [currPos.r][currPos.c];

    mlist * legalMoves = create_list();

    if ( currPawn.pcolor == white ){
        move nextPos = {.r = currPos.r - 1, .c = currPos.c};

        if (!isOutOfBounds(nextPos) && pieceCMP(board[nextPos.r][nextPos.c] , FREE_CELL)) {

            add_to_list(legalMoves, &nextPos); // 1 square ahead move

            if ( currPos.r == WHITE_PAWN_INITIAL_ROW && pieceCMP(board[nextPos.r - 2][nextPos.c] , FREE_CELL)) {
                add_to_list(legalMoves, &(move){currPos.r - 2, currPos.c});
            }
        }
    }

    return legalMoves;

}