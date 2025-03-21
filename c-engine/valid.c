#include "valid.h"

#define areOppositeColor(piece1, piece2) \
        ((isWhite(piece1) && isBlack(piece2)) || \
        (isWhite(piece2) && isBlack(piece1)))

#define areSameColor(piece1, piece2) \
        ((isWhite(piece1) && isWhite(piece2)) || \
        (isBlack(piece1) && isBlack(piece2)))



int isOutOfBounds(cell pos) {
    return (pos.r < 0 || pos.r >= ROWS || pos.c < 0 || pos.c >= COLUMNS);
}

ArrayStruct create_cell_array(List *moves) {
    ArrayStruct arrayStruct;
    int i = 0;

    if(moves != NULL){
        Node *current = moves->head;  

        while (current != NULL && i < 27) {
            cell *move = (cell *)current->data; 
            arrayStruct.arr[i].r = move->r;
            arrayStruct.arr[i].c = move->c;
            current = current->next;  
            i++;
        }
    }

    for (; i < 27; i++) {
        arrayStruct.arr[i].r = -1;
        arrayStruct.arr[i].c = -1;
    }
    return arrayStruct;
}

int isLegalMove ( BOARD board , move move_ , enum piece piece_ , cell currPos ) {
    int* move_ptr = (int*)&move_;
    switch(piece_){
        case B_PAWN: 
        case W_PAWN:
            return is_in_list( (void*)move_ptr , pawnLegalMoves( board , currPos ), compare_cells );
            break;

        case B_KNIGHT:
        case W_KNIGHT:
            return is_in_list( (void*)move_ptr , knightLegalMoves( board , currPos ), compare_cells );
            break;
        
        case B_BISHOP:
        case W_BISHOP:
            return is_in_list( (void*)move_ptr , bishopLegalMoves( board , currPos ), compare_cells );
            break;
        
        case B_ROOK:
        case W_ROOK:
            return is_in_list( (void*)move_ptr , rookLegalMoves( board , currPos ), compare_cells );
            break;
        
        case B_QUEEN:
        case W_QUEEN:
            return is_in_list( (void*)move_ptr , queenLegalMoves( board , currPos ), compare_cells );
            break;
        
        case B_KING:
        case W_KING:
            return is_in_list( (void*)move_ptr , kingLegalMoves( board , currPos ), compare_cells );
            break;

        default:
            return -1;
            break;
    }
}

void add_new_move (List * dest, move src){
        move* new_move = malloc(sizeof(move));
        if (new_move) {
            new_move->r = src.r;
            new_move->c = src.c;
            add_to_list(dest, new_move);
        }
}

ArrayStruct moveFinder(BoardReceiver boardArray, cell piecePos){
    FILE *f = fopen("../testMoves.txt", "w");//deletes old content
    BOARD board;
    convert_board(boardArray); //10 hours of my life have died on this line of code; WHY??? i forgot
    memcpy(board, global_board, sizeof(global_board));
    printb(board);
    List* moves = malloc(sizeof(List)); // Allocate memory for List
    moves->size = 0; // Initialize size
    moves->head = NULL;
    ArrayStruct arrayStruct = create_cell_array(NULL);

    fprintf(f, "Entering switch to choose piece, current piece %d", board[piecePos.r][piecePos.c]);
    switch(board[piecePos.r][piecePos.c]){
        case B_PAWN: 
        case W_PAWN:
            fprintf(f, "Selected pawn");
            moves = pawnLegalMoves(board, piecePos);
            arrayStruct = create_cell_array(moves);
            int i = 0;
            while(arrayStruct.arr[i].r != -1){
                fprintf(f, "\nMove 1: %d %d", arrayStruct.arr[i].r, arrayStruct.arr[i].c); //TEST THIS
                i++;
            }
            return arrayStruct;
            break;

        case B_KNIGHT:
        case W_KNIGHT:
            fprintf(f, "Selected knight");
            moves = knightLegalMoves(board, piecePos);
            arrayStruct = create_cell_array(moves);
            return arrayStruct;
            break;
        
        case B_BISHOP:
        case W_BISHOP:
            fprintf(f, "Selected bishop");
            moves = bishopLegalMoves(board, piecePos);
            arrayStruct = create_cell_array(moves);
            return arrayStruct;
            break;
        
        case B_ROOK:
        case W_ROOK:
            fprintf(f, "Selected rook");
            moves = rookLegalMoves(board, piecePos);
            arrayStruct = create_cell_array(moves);
            return arrayStruct;           
            break;
        
        case B_QUEEN:
        case W_QUEEN:
            fprintf(f, "Selected queen");
            moves = queenLegalMoves(board, piecePos);
            arrayStruct = create_cell_array(moves);
            for(int i = 0; i < 27; i++){
                fprintf(f, "%d %d\n", arrayStruct.arr[i].r, arrayStruct.arr[i].c);
            }
            return arrayStruct;            
            break;
        
        case B_KING:
        case W_KING:
            fprintf(f, "Selected king");
            moves = kingLegalMoves(board, piecePos);
            arrayStruct = create_cell_array(moves);
            return arrayStruct;           
            break;

        default:
            fprintf(f, "Unrecognized piece");
            return arrayStruct;
            break;
    }
    fclose(f);
}

List * pawnLegalMoves(BOARD board, cell currPos) {
    List * legalMoves = create_list();
    const enum piece currPawn = board[currPos.r][currPos.c];
    const int inc = isWhite(currPawn) ? 1 : -1;

    // 1 square ahead move
    move forwardOne = {currPos.r + inc, currPos.c};
    if (!isOutOfBounds(forwardOne) && 
        board[forwardOne.r][forwardOne.c] == EMPTY) {

        add_new_move(legalMoves, forwardOne);

    }

    // 2 squares ahead in the first move
    int pawnInitialRow = isWhite(currPawn) ? WHITE_PAWN_INITIAL_ROW : BLACK_PAWN_INITIAL_ROW;
    move forwardTwo = {currPos.r + 2 * inc, currPos.c};
    if (currPos.r == pawnInitialRow && !isOutOfBounds(forwardTwo) && 
        board[forwardTwo.r][forwardTwo.c] == EMPTY && board[forwardOne.r][forwardOne.c] == EMPTY) {

        add_new_move(legalMoves, forwardTwo);

    }

    // Left diagonal eat
    move leftDiagonal = {currPos.r + inc, currPos.c + inc};
    if (!isOutOfBounds(leftDiagonal) && 
        (areOppositeColor(board[leftDiagonal.r][leftDiagonal.c], currPawn) || 
        (board[leftDiagonal.r][leftDiagonal.c] == B_EN_PASSANT || board[leftDiagonal.r][leftDiagonal.c] == W_EN_PASSANT))) {

        add_new_move(legalMoves, leftDiagonal);


    }

    // Right diagonal eat
    move rightDiagonal = {currPos.r + inc, currPos.c - inc};
    if (!isOutOfBounds(rightDiagonal) && 
        areOppositeColor(board[rightDiagonal.r][rightDiagonal.c], currPawn) || 
        (board[rightDiagonal.r][rightDiagonal.c] == B_EN_PASSANT || board[rightDiagonal.r][rightDiagonal.c] == W_EN_PASSANT)) {
        add_new_move(legalMoves, rightDiagonal);
    }

    return legalMoves;
}


List * knightLegalMoves(BOARD board, cell currPos) {
    List * legalMoves = create_list();
    const enum piece currKnight = board[currPos.r][currPos.c];

    // Possible offsets for knight moves
    const int rowOffsets[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    const int colOffsets[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    const int numMoves = 8;
    int newRow;
    int newCol;

    // Check each possible move
    for (short int i = 0; i < numMoves; ++i) {
        newRow = currPos.r + rowOffsets[i];
        newCol = currPos.c + colOffsets[i];

        if (!isOutOfBounds((move){newRow, newCol}) && 
            (areOppositeColor(board[newRow][newCol], currKnight) || board[newRow][newCol] == EMPTY)) {

            add_new_move(legalMoves, (move){newRow, newCol});

        }
    }

    return legalMoves;
}

List * bishopLegalMoves(BOARD board, cell currPos) {
    List * legalMoves = create_list();
    const enum piece currBishop = board[currPos.r][currPos.c];

    for (short i = currPos.c - 1, j = currPos.r - 1; i >= 0 && j >= 0; --i, --j) { // upper left diagonal
        if (board[j][i] == EMPTY) {
            add_new_move(legalMoves, (move){j, i});
        } else if (areOppositeColor(board[j][i], currBishop)) {
            add_new_move(legalMoves, (move){j, i});
            break;
        }else {// same color
            break;
        }
    }

    for (short i = currPos.c - 1, j = currPos.r + 1; i >= 0 && j < ROWS; --i, ++j) { // lower left diagonal
        if (board[j][i] == EMPTY) {
            add_new_move(legalMoves, (move){j, i});
        } else if (areOppositeColor(board[j][i], currBishop)){
            add_new_move(legalMoves, (move){j, i});
            break;
        } else{// same color
            break;
        }
            
    }
    

    for (short i = currPos.c + 1, j = currPos.r - 1; i < COLUMNS && j >= 0; ++i, --j) { // upper right diagonal
        if (board[j][i] == EMPTY) {
            add_new_move(legalMoves, (move){j, i});
        } 
        else if (areOppositeColor(board[j][i], currBishop)) {
            add_new_move(legalMoves, (move){j, i});
            break;
        }else { // same color
            break;
        }
    }

    for (short i = currPos.c + 1, j = currPos.r + 1; i < COLUMNS && j < ROWS; ++i, ++j) { // lower right diagonal
        if (board[j][i] == EMPTY) {
            add_new_move(legalMoves, (move){j, i});
        } else if (areOppositeColor(board[j][i], currBishop)) {
            add_new_move(legalMoves, (move){j, i});
            break;
        } else{// same color
            break;
        }   
    }
    
    return legalMoves;
}

List * rookLegalMoves(BOARD board, cell currPos) {
    List * legalMoves = create_list();
    const enum piece currRook = board[currPos.r][currPos.c];

    // Check moves to the left
    for (short i = currPos.c - 1; i >= 0; --i) {
        if (board[currPos.r][i] == EMPTY) {
            add_new_move(legalMoves, (move){currPos.r, i});
        } else if (areOppositeColor(board[currPos.r][i], currRook)) {
            add_new_move(legalMoves, (move){currPos.r, i});
            break;
        } else { // same color
            break;
        }
    }

    // Check moves to the right
    for (short i = currPos.c + 1; i < COLUMNS; ++i) {
        if (board[currPos.r][i] == EMPTY) {
            add_new_move(legalMoves, (move){currPos.r, i});
        } else if (areOppositeColor(board[currPos.r][i], currRook)) {
            add_new_move(legalMoves, (move){currPos.r, i});
            break;
        } else { // same color
            break;
        }
    }

    // Check moves upwards
    for (short j = currPos.r - 1; j >= 0; --j) {
        if (board[j][currPos.c] == EMPTY) {
            add_new_move(legalMoves, (move){j, currPos.c});
        } else if (areOppositeColor(board[j][currPos.c], currRook)) {
            add_new_move(legalMoves, (move){j, currPos.c});
            break;
        } else { // same color
            break;
        }
    }

    // Check moves downwards
    for (short j = currPos.r + 1; j < ROWS; ++j) {
        if (board[j][currPos.c] == EMPTY) {
            add_new_move(legalMoves, (move){j, currPos.c});
        } else if (areOppositeColor(board[j][currPos.c], currRook)) {
            add_new_move(legalMoves, (move){j, currPos.c});
            break;
        } else { // same color
            break;
        }
    }

    return legalMoves;
}

List * queenLegalMoves (BOARD board, cell currPos){
    return  merge_lists(bishopLegalMoves(board,currPos), rookLegalMoves(board, currPos));
}

List * kingLegalMoves (BOARD board, cell currPos){
    List * legalMoves = create_list();
    const enum piece currKing = board[currPos.r][currPos.c];

    // Possible offsets for king moves
    const int posOffsets[] = { -1, 0, 1};
    const int numMoves = 3;
    int newRow;
    int newCol;

    // Check each possible move
    for (short int i = 0; i < numMoves; ++i) {
        for(short int j = 0; j < numMoves; j++){

            if( i == 1 && j == 1) continue;

            newRow = currPos.r + posOffsets[i];
            newCol = currPos.c + posOffsets[j];

            if (!isOutOfBounds((move){newRow, newCol}) && 
                (areOppositeColor(board[newRow][newCol], currKing) || board[newRow][newCol] == EMPTY)) {
                add_new_move(legalMoves, (move){newRow, newCol});
            }

        }
    }

    return legalMoves;
}