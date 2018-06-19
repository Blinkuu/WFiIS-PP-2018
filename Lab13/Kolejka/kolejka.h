#include <stdio.h>
#define ENQUEUE insert_item_end
#define DEQUEUE pop

typedef struct _node {
 int value;
 struct _node *next;
}node;

node * insert_item_end (node *,int);
void print_list (node *);
int pop (node **);


