
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
  #define _FREE_  -1


  //black pieces struct definition
  #define BLACK_PAWN    ((piece){.ptype = p, .pcolor = black})
  #define BLACK_BISHOP  ((piece){.ptype = b, .pcolor = black})
  #define BLACK_KNIGHT  ((piece){.ptype = n, .pcolor = black})
  #define BLACK_ROOK    ((piece){.ptype = r, .pcolor = black})
  #define BLACK_QUEEN   ((piece){.ptype = q, .pcolor = black})
  #define BLACK_KING    ((piece){.ptype = k, .pcolor = black})

  //white pieces struct definition
  #define WHITE_PAWN    ((piece){.ptype = p, .pcolor = white})
  #define WHITE_BISHOP  ((piece){.ptype = b, .pcolor = white})
  #define WHITE_KNIGHT  ((piece){.ptype = n, .pcolor = white})
  #define WHITE_ROOK    ((piece){.ptype = r, .pcolor = white})
  #define WHITE_QUEEN   ((piece){.ptype = q, .pcolor = white})
  #define WHITE_KING    ((piece){.ptype = k, .pcolor = white})

  #define FREE_CELL     ((piece){.ptype = no_type, .pcolor = no_color})


  typedef struct{

    signed char r ; // ROW

    signed char c ; // COLUMN

  } cell;

  enum type{
    k       = 2,
    p       = PAWN, 
    n       = KNIGHT, 
    b       = BISHOP, 
    r       = ROOK, 
    q       = QUEEN,
    no_type = _FREE_
  };

  enum color{

    black, 
    white,
    no_color = _FREE_

  };

  typedef struct{

    enum type  ptype;

    enum color pcolor;

  } piece;

  typedef struct {

    piece mpiece;

    cell  from;

    cell  to;

  } move;

  typedef struct {
      
      List * whitePieces;

      List * blackPieces;

      stack * moves;

  } boardInfo;

  typedef struct _mlist{
      
      move move_;
  
      struct _mlist * next;
      
  } mlist;

  typedef struct _plist{

    piece piece_;

    struct _plist * next;

  } plist;

  typedef piece BOARD[ROWS][COLUMNS];

  // board [pos] => piece

#endif