#include <stdlib.h>
#include <stdio.h>
#include "kolejka.h"

int pop (node ** head ) {
	int val = (*head)->value;

	node *tmp = *head;
	*head = (*head)->next;

	free(tmp);

	return val;
}

node *insert_item_end (node * head,int val){
	node * temp = (node *) malloc(sizeof(node));

	if (!temp){
		printf("Brak pamieci!!!\n");
		exit(1);
	}
	
	temp->value = val;
	temp->next = NULL;
	if(head){
		node *ele = head;
		while(ele->next){
			ele = ele->next;		
		}
		ele->next = temp;
	} else{
		head = temp;
	}
	return head;
}

void print_list (node* head){
    if(!head){
        printf("Kolejka jest pusta!");
        return;
    }
    node *wsk = head;
    while(wsk)
    {
        printf("%d\n",wsk->value);
        wsk=wsk->next;
    }
}
