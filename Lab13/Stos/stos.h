#ifndef _STOS_H_
#define _STOS_H_
#define PUSH insert_item_begin

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
 int value;
 struct tnode *next;
}node;

node * insert_item_begin (node *,int);
void print_list (node *);
int pop (node **);

#endif
