#include <stdio.h>
#include <stdlib.h>

struct NODE {
    struct NODE *next;
    int data;
};

void append(struct NODE **head_node, int new_data) {
    struct NODE *new_node = (struct NODE *) malloc(sizeof(struct NODE));
    struct NODE *last = *head_node;

    new_node->data  = new_data;
    new_node->next = NULL;
 
    if (*head_node == NULL) {
       *head_node = new_node;
       return;
    } 

    while (last->next != NULL)
        last = last->next;
  
    last->next = new_node;
    return;   
}

void push(struct NODE **head_node, int new_data) {
    struct NODE *new_node = (struct NODE *)malloc(sizeof(struct NODE));
    new_node->next = (*head_node);
    new_node->data = new_data;
    
    (*head_node) = new_node;
}

void insert_after(struct NODE *prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");    
        return;
    }

    struct NODE *new_node =(struct Node *) malloc(sizeof(struct NODE));
    
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
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

void delete_list(struct NODE** head_node) {
   struct NODE *current = *head_node;
   struct NODE *next;
 
   while (current != NULL) {
       next = current->next;
       free(current);
       current = next;
   }

   *head_node = NULL;
}
