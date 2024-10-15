#include "./board.h"
#include "types.h"
#include "valid.h"
#include <stdio.h>

int main(){

  BOARD board;

  INIT_BOARD(board);

  Node * tmp = pawnLegalMoves(board, (cell){6, 4})->head;
  printf("mosse legali bPawn da 6-4\n");
  while(tmp){
    printf ("%d %d\n", (*(move *)tmp->data).r ,(*(move *)tmp->data).c);
    tmp = tmp->next;
  }
  
  return 0;

}

//This main is basically only useful if you wanto to use the engine without the python side.

/*
Node * tmp = bishopLegalMoves(board, (cell){3, 5})->head;
  printf("mosse legali wBishop da 3-5\n");
  while(tmp){
    printf ("%d %d\n", (*(move *)tmp->data).r ,(*(move *)tmp->data).c);
    tmp = tmp->next;
  }

printf("\n\nPawn a2 (1-7) to a3(2-7):\n ");
  printf("%d\n", isLegalMove( board, (cell){2,7}, W_PAWN, (cell){1,7}));
*/