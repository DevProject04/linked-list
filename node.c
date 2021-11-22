#include <stdio.h>
#include <stdlib.h>

struct NODE {
    struct NODE *next;
    int data;
};

void push(struct NODE **head_node, int new_data) {
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->next = (*head_node);
    new_node->data = new_data;
    
    (*head_node) = new_node;
}

void delete_node(struct NODE **head_node, int key) {
    struct NODE *temp = *head_node, *prev;

    if (temp != NULL && temp->data == key) {
        *head_node = temp->next;
        free(temp);

        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void node_list(struct NODE *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}