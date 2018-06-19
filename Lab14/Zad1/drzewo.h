#ifndef _TREE_H_
#define _TREE_H_

typedef struct bstree {
	int key;
	struct bstree *left;
	struct bstree *right;
	struct bstree *parent;
} bstree;

bstree *CreateLeaf(int a, bstree *p);
void  AddLeaf(int a, bstree  **tr , bstree *parent);
void  PrintTreePreorder(const  bstree *tr);

#endif
