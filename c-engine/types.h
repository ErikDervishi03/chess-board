
#ifndef __TYPES_H__
#define __TYPES_H__

  #ifndef true
    #define true 1
  #endif

  #ifndef false
    #define false 0
  #endif

  #define ROWS    8
  #define COLUMNS 8

  #define PAWN    1
  #define BISHOP  3
  #define KNIGHT  3
  #define ROOK    5
  #define QUEEN   9

  #define WHITE_PAWN_INITIAL_ROW 1
  #define BLACK_PAWN_INITIAL_ROW 6



  typedef struct node {

    void* data;

    struct node* next;

  } Node;
 
  typedef struct list {

    int size;

    Node* head;
    
  } List;

  typedef struct{

    int r ; // ROW

    int c ; // COLUMN

  } cell;

  typedef struct {

    cell arr[27]; 

} ArrayStruct;

  typedef cell move;

  enum piece {

    B_PAWN  ,
    B_KNIGHT,
    B_BISHOP,
    B_ROOK  ,
    B_QUEEN ,
    B_KING  ,

    W_PAWN  ,
    W_KNIGHT,
    W_BISHOP,
    W_ROOK  ,
    W_QUEEN ,  
    W_KING  ,

    EMPTY,

    B_EN_PASSANT,
    W_EN_PASSANT

  };

  typedef struct {
      
      List * whitePieces;

      List * blackPieces;

      List * moves;//treated as a stack by stack.c, not declared as stack here for dependency reasons

  } boardInfo;

  typedef List mlist; // move list

  typedef List plist; // piece list

  typedef enum piece BOARD[ROWS][COLUMNS];

  typedef int BoardReceiver[64];

  extern BOARD global_board;

#endif