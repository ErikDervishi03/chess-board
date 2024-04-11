#ifndef __VALID_H__
#define __VALID_H__

#include "types.h"

// idea create a bit mask in order to check wich error is active 

int isOutOfBounds(int row, int col);

int isLegalMove ( BOARD board , move move_);

#endif // __VALID_H__