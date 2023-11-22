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
    return tree;
}

bool isEmptyTree(head__t *tree) {
    return (tree->root == NULL && tree->size == 0);
}

response__t* insert(head__t *tree, void* data) {
    response__t *result = newInstance();
    if(isEmptyTree(tree)) {

    }
    else {

    }
    return result;
}
