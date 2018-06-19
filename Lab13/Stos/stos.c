#include <stdlib.h>
#include <stdio.h>
#include "stos.h"

node * insert_item_begin (node *head,int val){
	node *temp=malloc(sizeof(node));
    if(!temp){
        printf("Brak pamieci!!!\n");
        return head;
    }
    temp->value=val ;
    temp->next=head ;
    return temp;
}
void print_list (node* head){
    if(!head){
        printf("Stos jest pusty!");
        return;
    }
    node *wsk = head;
    while(wsk)
    {
        printf("%d\n",wsk->value);
        wsk=wsk->next;
    }
}
int pop (node** head){
	int val = (*head)->value;

	node *tmp = *head;
	*head = (*head)->next;

	free(tmp);

	return val;
}
