#include<criterion/criterion.h>
#include "../src/tree.h"

head__t *tree = NULL;

int intComparator(void* op1, void* op2) {
    assert(NULL != op1 && NULL != op2);
    int *iop1 = (int*) op1;
    int *iop2 = (int*) op2;
    return (*iop1 > *iop2 ? 1 : (*iop1 < *iop2 ? -1 : 0));
}

void setup() {
    tree = createTree(intComparator);
}

void teardown() {
    if(tree) {
        tree = NULL;
    }
}

Test(TreeTest, CreateTree, .init=setup, .fini=teardown) {
    cr_assert(tree != NULL);
}

Test(TreeTest, isEmptyTree, .init=setup, .fini=teardown) {
    cr_assert(isEmptyTree(tree) == true, "Tree must be empty"); 
}