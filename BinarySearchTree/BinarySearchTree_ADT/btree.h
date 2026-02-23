#ifndef BTREE_H
#define BTREE_H

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_bst(struct node* root, int val);
void preorderTraversal(struct node* root);
void inorderTraversal(struct node* root);
void postorderTraversal(struct node* root);
int findHeight(struct node* root);
int nodeHeight(struct node* root, int val);
int countInternalNodes(struct node* root);
int countExternalNodes(struct node* root);
int exists(struct node* root, int val);

#endif
