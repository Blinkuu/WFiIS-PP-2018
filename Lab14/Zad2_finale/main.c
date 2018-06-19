#include "drzewo.h"
#include <stdlib.h>
#include <stdio.h>

int main (void){

	int tab[] = {15,5,16,20,3,12,18,23,10,13,6,7};
	
	bstree *root = NULL;
	for(int i = 0; i < sizeof(tab)/sizeof(tab[0]); i++){
		AddLeaf(tab[i], &root ,NULL);
	}
	PrintTreePreorder(root);
	return 0;
}
