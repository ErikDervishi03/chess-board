#ifndef __STACK_H__
#define __STACK_H__

#include "./listc.h"

typedef List stack;

void init_stack(stack *_stack) {
    _stack = create_list();
}

/* Function to add a node at the beginning of Linked List.
   This function expects a pointer to the data to be added
   and size of the data type */
void push2stack(stack * head_ref, void *new_data, size_t data_size)
{
    // Allocate memory for node
    Node* new_node = (Node*)malloc(sizeof(Node));
 
    new_node->data  = malloc(data_size);
    new_node->next = (head_ref->head->next);
    
    // Copy contents of new_data to newly allocated memory.
    memcpy (&new_node->data, new_data, data_size);
 
    // Change head pointer as new node is added at the beginning
    (head_ref->head)    = new_node;
}

void* pop (stack * head_ref) {
    if (head_ref == NULL || head_ref->size == 0) {
        return NULL;
    }
    Node* temp = head_ref->head;
    head_ref->head = head_ref->head->next;
    void* popped = temp->data;
    
    free(temp);
    return popped;
}

#endif // __STACK_H__