#ifndef _RESEARCH_TREE_H_
#define _RESEARCH_TREE_H_ 1

#include "common.h"

typedef struct TreeHead head__t;
typedef struct TreeNode node__t;
typedef int (*comparator)(void*, void*);

head__t* createTree(comparator);
bool isEmptyTree(head__t*);
void insert(head__t*, void*);

#endif
