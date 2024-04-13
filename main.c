#include "./board.h"
#include "data_structure/listc.h"
#include "types.h"
#include "valid.h"
#include <stdio.h>

int main(){

  BOARD board;

  INIT_BOARD(board);

  Node * tmp = queenLegalMoves(board, (cell){1, 3})->head;

  printf("mosse legali\n");

  
  while(tmp){

    printf ("%d %d\n", (*(move *)tmp->data).r ,(*(move *)tmp->data).c);
    tmp = tmp->next;
  }

  printb(board);
  
  return 0;

}