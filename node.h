#ifndef __NODE_H__
#define __NODE_H__

void push(struct NODE **head_node, int new_data);
void delete_node(struct NODE **head_node, int key);
void node_list(struct NODE *node);

#endif