#include "tree.h"

struct TreeNode {
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeHead
{
    struct TreeNode *root;
    size_t size;
    int (*compare)(void*, void*);
};

head__t* createTree(comparator cmp) {
    head__t *tree = (head__t*) malloc(sizeof(head__t));
    if(tree) {
        tree->root = NULL;
        tree->size = 0;
        tree->compare = cmp;
    }
    else {
        perror("ERROR: failed to create tree\n");
    }
    return tree;
}

node__t* createNode(void*, node__t*, node__t*) {
    node__t *node = (node__t*) malloc(sizeof(node__t));
    if(node) {
        printf("ABCD");
    }
    else {
        printf("ABCD");
    }
    return node;
}

bool isEmptyTree(head__t *tree) {
    return (tree->root == NULL && tree->size == 0);
}

void __insert(head__t *tree, void *data) {
    
        if(isEmptyTree(tree)) {

        }
        else {

        }
}



response__t* insert(head__t *tree, void* data) {
    response__t *result = NULL;
    if(tree) {
        result = newInstance();
        __insert(tree, data);
    }
    
    return result;
}

node__t* createNode(void *data, node__t *leftNode, node__t *rightNode) {
    node__t *result = (node__t*) malloc(sizeof(node__t));
    if(result) {    
        result->data = data;
        result->left = leftNode;
        result->right = rightNode;
    }
    else {
        perror("ERROR: failed to create tree\n");
    }
    return result;
}