#ifndef __LISTC_H__
#define __LISTC_H__

#include <stdlib.h>
#include "../types.h"

/* https://www.geeksforgeeks.org/generic-linked-list-in-c-2/ */

enum piece;
 
List* create_list();
 
void add_to_list(List* list, void* data);
 
void* remove_from_list(List* list);

int is_in_list( void* element, List* list, int (*cmp)(const void*, const void*) );
 
void free_list(List* list);

List * merge_lists (List * dest, List * src);

int compare_pieces(const void* a, const void* b);

int compare_cells(const void* a, const void* b);

#endif // __LISTC_H__