#ifndef _RESEARCH_TREE_H_
#define _RESEARCH_TREE_H_ 1

#include "common.h"
#include "response.h"

typedef struct TreeHead head__t;
typedef struct TreeNode node__t;
typedef int (*comparator)(void*, void*);

head__t* createTree(comparator);
node__t* createNode(void*, node__t*, node__t*);
bool isEmptyTree(head__t*);
response__t* insert(head__t*, void*);

#endif
