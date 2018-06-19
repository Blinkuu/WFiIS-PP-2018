#include <stdlib.h>
#include <stdio.h>
#include "drzewo.h"
#define REL(a,b) (a) >(b)?(1) :(0)

bstree *CreateLeaf(int a, bstree *p){
	bstree *t = malloc(sizeof(bstree));
		if (!t){
			printf("Brak pamieci !!!\n");
			return  NULL;
		}
	t->key=a;
	t->left=t->right=NULL;
	t->parent=p;
	return t;
}

void  AddLeaf(int a, bstree  **tr , bstree *parent){
	if(*tr){
		if(REL ((*tr)->key , a))
			AddLeaf(a,&(*tr)->left , *tr);
		else
			AddLeaf(a,&(*tr)->right , *tr);
	} else
		*tr = CreateLeaf(a, parent);
}

void  PrintTreePreorder(const  bstree *tr){
	if(tr){
		printf("adress :%p, key:%d, left ->%p, right->%p, parent ->%p\n", tr , tr ->key , tr ->left , tr->right , tr->parent);
		PrintTreePreorder(tr ->left);
		PrintTreePreorder( tr ->right);
	}
}

