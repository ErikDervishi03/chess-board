#include "board.h"
#include "types.h"
#include <stdio.h>

int main(){

  BOARD board;

  INIT_BOARD(board);

  printf("%d",board[3][3].ptype);

  return 0;

}