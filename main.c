#include "./board.h"
#include "data_structure/listc.h"
#include "types.h"
#include "valid.h"
#include <stdio.h>

int main(){

  BOARD board;

  INIT_BOARD(board);

  do_move(board, (move){7,0}, (move){2,0});

  Node * tmp = pawnLegalMoves(board, (cell){1, 1})->head;

  printf("mosse legali\n");

  
  while(tmp){

    printf ("%d %d\n", (*(move *)tmp->data).r ,(*(move *)tmp->data).c);
    tmp = tmp->next;
  }

  printb(board);
  
  return 0;

}