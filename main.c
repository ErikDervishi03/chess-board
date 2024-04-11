#include "./board.h"
#include <stdio.h>

int main(){

  BOARD board;

  INIT_BOARD(board);

  move move_ = {.mpiece = board[0][0].ptype, .from = { 0 , 0 }, .to = { 0 , 0 }};

  do_move(&board, move_);

  printf("%d",board[0][0].ptype);

  return 0;

}