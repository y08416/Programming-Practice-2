#ifndef NODE_H
#define NODE_H

struct node {
    int key;
    struct node *parent, *left, *right;
};

struct node *new_node(int key);
void print_tree(struct node *node, int depth);

#endif
