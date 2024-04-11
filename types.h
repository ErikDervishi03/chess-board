
#ifndef __TYPES_H__
#define __TYPES_H__

  #define ROWS 8
  #define COLUMNS 8

  #define PAWN 1
  #define BISHOP 3
  #define KNIGHT 3
  #define ROOK 5
  #define QUEEN 9
  #define _FREE_ -1 


  //black pieces struct definition
  #define BLACK_PAWN    {.ptype = p, .pcolor = black}
  #define BLACK_BISHOP  {.ptype = b, .pcolor = black}
  #define BLACK_KNIGHT  {.ptype = n, .pcolor = black}
  #define BLACK_ROOK    {.ptype = r, .pcolor = black}
  #define BLACK_QUEEN   {.ptype = q, .pcolor = black}
  #define BLACK_KING    {.ptype = k, .pcolor = black}

  //white pieces struct definition
  #define WHITE_PAWN    {.ptype = p, .pcolor = white}
  #define WHITE_BISHOP  {.ptype = b, .pcolor = white}
  #define WHITE_KNIGHT  {.ptype = n, .pcolor = white}
  #define WHITE_ROOK    {.ptype = r, .pcolor = white}
  #define WHITE_QUEEN   {.ptype = q, .pcolor = white}
  #define WHITE_KING    {.ptype = k, .pcolor = white}

  #define FREE_CELL     {.ptype = no_type, .pcolor = no_color}

  typedef struct{

    signed char r ; // ROW

    signed char c ; // COLUMN

  }cell ;

  enum type{
    k,
    p = PAWN, 
    n = KNIGHT, 
    b = BISHOP, 
    r = ROOK, 
    q = QUEEN,
    no_type = _FREE_
  };

  enum color{

    black, 
    white,
    no_color = _FREE_

  };

  typedef struct{

    enum type ptype;

    enum color pcolor;

  } piece;

  typedef piece BOARD[ROWS][COLUMNS];

  // board [pos] => piece

#endif