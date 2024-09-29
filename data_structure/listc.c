#include "./listc.h"

int compare_pieces(const void* a, const void* b) {
    enum piece piece1 = *(enum piece*)a;
    enum piece piece2 = *(enum piece*)b;
    return piece1 == piece2;
}

int compare_cells(const void* a, const void* b) {
    cell* cell1 = (cell*)a;
    cell* cell2 = (cell*)b;
    return (cell1->r == cell2->r) && (cell1->c == cell2->c);
}

List* create_list() {
    List* new_list = (List*)malloc(sizeof(List));
    new_list->size = 0;
    new_list->head = NULL;
    return new_list;
}

void add_to_list(List* list, void* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void* remove_from_list(List* list) {
    if (list->size == 0) {
        return NULL;
    }
    Node* node_to_remove = list->head;
    void* data = node_to_remove->data;
    list->head = node_to_remove->next;
    free(node_to_remove);
    list->size--;
    return data;
}

int is_in_list(void* element, List* list, int (*cmp)(const void*, const void*)) {//passare compare_pieces oppure compare_cells come parametro
    Node* current = list->head;
    while (current != NULL) {
        if (cmp(element, current->data)) {
            return 1;  // Element found in the list
        }
        current = current->next;
    }
    return 0;  // Element not found
}

void free_list(List* list) {
    Node* current_node = list->head;
    while (current_node != NULL) {
        Node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

List * merge_lists(List * dest, List * src) {
    if (src == NULL || src->size == 0) {
        // Nothing to merge
        return dest;
    }
    
    if (dest == NULL) {
        // If the destination list is NULL, create a new list
        dest = create_list();
    }

    if (dest->size == 0) {
        // If the destination list is empty, set its head to the head of the source list
        dest->head = src->head;
    } else {
        // Otherwise, find the last node of the destination list
        Node *last_node = dest->head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        // Append the head of the source list to the last node of the destination list
        last_node->next = src->head;
    }

    // Update the size of the destination list
    dest->size += src->size;

    // Free the source list structure, but not its nodes
    free(src);

    // Return the merged destination list
    return dest;
}
