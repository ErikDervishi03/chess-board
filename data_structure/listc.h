#ifndef __LISTC_H__
#define __LISTC_H__

#include <stdlib.h>

/* https://www.geeksforgeeks.org/generic-linked-list-in-c-2/ */

typedef struct node {

    void* data;

    struct node* next;

} Node;
 
typedef struct list {

    int size;

    Node* head;
    
} List;
 
List* create_list();
 
void add_to_list(List* list, void* data);
 
void* remove_from_list(List* list);
 
void free_list(List* list);

List * merge_lists (List * dest, List * src);

#endif // __LISTC_H__