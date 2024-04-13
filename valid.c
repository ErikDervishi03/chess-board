#include "valid.h"
#include "data_structure/listc.h"
#include "types.h"
#include <stdio.h>


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

void add_new_move (List * dest, move src){
        move* new_move = malloc(sizeof(move));
        if (new_move) {
            new_move->r = src.r;
            new_move->c = src.c;
            add_to_list(dest, new_move);
        }
}

List * pawnLegalMoves(BOARD board, cell currPos) {
    List * legalMoves = create_list();
    const piece currPawn = board[currPos.r][currPos.c];
    const int inc = (currPawn.pcolor == white) ? 1 : -1;

    // 1 square ahead move
    move forwardOne = {currPos.r + inc, currPos.c};
    if (!isOutOfBounds(forwardOne) && 
        pieceCMP(board[forwardOne.r][forwardOne.c], FREE_CELL)) {

        add_new_move(legalMoves, forwardOne);

    }

    // 2 squares ahead in the first move
    int pawnInitialRow = (currPawn.pcolor == white) ? WHITE_PAWN_INITIAL_ROW : BLACK_PAWN_INITIAL_ROW;
    move forwardTwo = {currPos.r + 2 * inc, currPos.c};
    if (currPos.r == pawnInitialRow && !isOutOfBounds(forwardTwo) && 
        pieceCMP(board[forwardTwo.r][forwardTwo.c], FREE_CELL)) {

        add_new_move(legalMoves, forwardTwo);

    }

    // Left diagonal eat
    move leftDiagonal = {currPos.r + inc, currPos.c - 1};
    if (!isOutOfBounds(leftDiagonal) && 
        areOppositeColor(board[leftDiagonal.r][leftDiagonal.c].pcolor, currPawn.pcolor)) {

        add_new_move(legalMoves, leftDiagonal);


    }

    // Right diagonal eat
    move rightDiagonal = {currPos.r + inc, currPos.c + 1};
    if (!isOutOfBounds(rightDiagonal) && 
        areOppositeColor(board[rightDiagonal.r][rightDiagonal.c].pcolor, currPawn.pcolor)) {
        add_new_move(legalMoves, rightDiagonal);
    }

    return legalMoves;
}


List * knightLegalMoves(BOARD board, cell currPos) {
    List * legalMoves = create_list();
    const piece currKnight = board[currPos.r][currPos.c];

    // Possible offsets for knight moves
    const int rowOffsets[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int colOffsets[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    const int numMoves = 8;
    int newRow;
    int newCol;

    // Check each possible move
    for (int i = 0; i < numMoves; ++i) {
        newRow = currPos.r + rowOffsets[i];
        newCol = currPos.c + colOffsets[i];

        if (!isOutOfBounds((move){newRow, newCol}) && 
            board[newRow][newCol].pcolor != currKnight.pcolor) {

            add_new_move(legalMoves, (move){newRow, newCol});

        }
    }

    return legalMoves;
}

List * bishopLegalMoves(BOARD board, cell currPos) {
    List * legalMoves = create_list();
    const piece currBishop = board[currPos.r][currPos.c];

    for (short i = currPos.c - 1, j = currPos.r - 1; i >= 0 && j >= 0; --i, --j) { // upper left diagonal
        if (pieceCMP(board[j][i], FREE_CELL)) {
            add_new_move(legalMoves, (move){j, i});
        } else if (areOppositeColor(board[j][i].pcolor, currBishop.pcolor)) {
            add_new_move(legalMoves, (move){j, i});
            break;
        }else {// same color
            break;
        }
    }

    for (short i = currPos.c - 1, j = currPos.r + 1; i >= 0 && j < ROWS; --i, ++j) { // lower left diagonal
        if (pieceCMP(board[j][i], FREE_CELL)) {
            add_new_move(legalMoves, (move){j, i});
        } else if (areOppositeColor(board[j][i].pcolor, currBishop.pcolor)){
            add_new_move(legalMoves, (move){j, i});
            break;
        } else{// same color
            break;
        }
            
    }
    

    for (short i = currPos.c + 1, j = currPos.r - 1; i < COLUMNS && j >= 0; ++i, --j) { // upper right diagonal
        if (pieceCMP(board[j][i], FREE_CELL)) {
            add_new_move(legalMoves, (move){j, i});
        } 
        else if (areOppositeColor(board[j][i].pcolor, currBishop.pcolor)) {
            add_new_move(legalMoves, (move){j, i});
            break;
        }else { // same color
            break;
        }
            
        
    }

    for (short i = currPos.c + 1, j = currPos.r + 1; i < COLUMNS && j < ROWS; ++i, ++j) { // lower right diagonal
        if (board[j][i].ptype == no_type) {
            add_new_move(legalMoves, (move){j, i});
        } else if (areOppositeColor(board[j][i].pcolor, currBishop.pcolor)) {
            add_new_move(legalMoves, (move){j, i});
            break;
        } else{// same color
            break;
        }
            
    }
    

    return legalMoves;
}
