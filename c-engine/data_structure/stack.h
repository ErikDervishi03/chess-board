#ifndef __STACK_H__
#define __STACK_H__

#include "./listc.h"
#include "string.h"

typedef List stack;

void init_stack(stack *_stack);

/* Function to add a node at the beginning of Linked List.
   This function expects a pointer to the data to be added
   and size of the data type */
void push2stack(stack * head_ref, void *new_data, size_t data_size);

void* pop (stack * head_ref);

#endif // __STACK_H__