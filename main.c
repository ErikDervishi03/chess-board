#include "./board.h"
#include "data_structure/listc.h"
#include "types.h"
#include "valid.h"
#include <stdio.h>

int main(){

  BOARD board;

  INIT_BOARD(board);

  Node * tmp = kingLegalMoves(board, (cell){3, 3})->head;

  printf("mosse legali\n");

  
  while(tmp){

    printf ("%d %d\n", (*(move *)tmp->data).r ,(*(move *)tmp->data).c);
    tmp = tmp->next;
  }

  printf("\nBOARD\n");

  printb(board);

  printf("\n\nPawn h2 (1-7) to h3\n: ");
  printf("%d", isLegalMove( board, (cell){2,7}, W_PAWN, (cell){1,7}));
  
  return 0;

}