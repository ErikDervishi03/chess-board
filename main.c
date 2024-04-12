#include "./board.h"
#include "types.h"

int main(){

  BOARD board;

  INIT_BOARD(board);

  move move_ = { 2 , 2};

  // do_move(board, move_);

  boardInfo x = extractBoardInfo(board);

  //push2stack(x.moves, &move_, sizeof(move));

  printb(board);

  
  return 0;

}