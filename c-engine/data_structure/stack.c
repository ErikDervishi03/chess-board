#include "./stack.h"
#include <stdio.h>
void init_stack(stack *_stack) {
    _stack = create_list();
}

void push2stack(stack * head_ref, void *new_data, size_t data_size)
{
    // Allocate memory for node
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;
    
    new_node->next = head_ref->head;

    head_ref->head = new_node;
    
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