#include "./board.h"
#include "types.h"
#include "valid.h"
#include <stdio.h>

int main(){

  BOARD board;

  INIT_BOARD(board);

  Node * tmp = bishopLegalMoves(board, (cell){3, 5})->head;
  printf("mosse legali wBishop da 3-5\n");
  while(tmp){
    printf ("%d %d\n", (*(move *)tmp->data).r ,(*(move *)tmp->data).c);
    tmp = tmp->next;
  }

  printf("\nBOARD(black POV)\n");

  printb(board);
  
  return 0;

}

/*
printf("\n\nPawn a2 (1-7) to a3(2-7):\n ");
  printf("%d\n", isLegalMove( board, (cell){2,7}, W_PAWN, (cell){1,7}));
*/