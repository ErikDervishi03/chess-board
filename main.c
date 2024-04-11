#include "./board.h"
#include "types.h"

int main(){

  BOARD board;

  INIT_BOARD(board);

  move move_ = {.mpiece = board[0][0], .from = { 0 , 0 }, .to = { 2 , 2}};

  // do_move(board, move_);

  boardInfo x = extractBoardInfo(board);

  //push2stack(x.moves, &move_, sizeof(move));

  printb(board);

  
  return 0;

}