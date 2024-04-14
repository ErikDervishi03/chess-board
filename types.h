
#ifndef __TYPES_H__
#define __TYPES_H__

#include "./data_structure/listc.h"
#include "./data_structure/stack.h"

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

  typedef struct{

    int r ; // ROW

    int c ; // COLUMN

  } cell;

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

    EMPTY

  };

  typedef struct {
      
      List * whitePieces;

      List * blackPieces;

      stack * moves;

  } boardInfo;

  typedef List mlist; // move list

  typedef List plist; // piece list

  typedef enum piece BOARD[ROWS][COLUMNS];

  // board [pos] => piece

#endif