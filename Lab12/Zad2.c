#include <stdio.h>
#include <stdlib.h>
 
struct tnode{
    int value;
    struct tnode *next;
};
 
struct tnode* dodaj_na_poczatek (struct tnode *head, int val){
    struct tnode *temp=malloc(sizeof(struct tnode));
    if(!temp){
        printf("Brak pamieci!!!\n");
        return head;
    }
    temp->value=val ;
    temp->next=head ;
    return temp;
}
 
void dodaj_na_koniec (struct tnode **head, int val){
    struct tnode *temp=malloc(sizeof(struct tnode));
    if(!temp) return;
    temp->value=val;
    temp->next=NULL;
    if(*head){
        struct tnode *ele=*head;
        for(;ele->next;ele=ele->next);
        ele->next=temp;
    }
    else
        *head=temp;
}
 
struct tnode *dodaj_do_posortowanej(struct tnode *head, int val){
    struct tnode *elem=malloc(sizeof(struct tnode));
    if(!elem)
        return head;
    elem->value=val;
    elem->next=NULL;
    if(head){
        if(head->value>val){
            elem->next=head;
            head=elem;
        }
        else{
            struct tnode *tp=head;
            for(;tp->next && tp->next->value < val;tp=tp->next);
            elem->next=tp->next;
            tp->next=elem;
        }
    }
    else
        head=elem;
    return head;
}
 
void printList(struct tnode* head){
    if(!head){
        printf("Lista jest pusta!");
        return;
    }
    struct tnode *wsk = head;
    while(wsk)
    {
        printf("%d\n",wsk->value);
        wsk=wsk->next;
    }
}
 
struct tnode *wyczysc(struct tnode *elem){
    while(elem){
        struct tnode *next=elem->next;
        free(elem);
        elem=next;
    }
    return NULL;
}
 
 
void szukaj(struct tnode *elem, int key){
    for(;elem && elem->value!=key;elem=elem->next);
    if(elem){
        printf("Znaleziono %d pod adresem : %p\n",elem->value,elem);
    }
    else
         printf("Nie znaleziono wartosci\n");
}
 
struct tnode *usun(struct tnode *head, int key){
    struct tnode *cur=head, *prev=NULL;
    for(;cur && cur->value!=key;prev=cur,cur=cur->next);
    if(!cur){
        printf("Nie znaleziono wartosci\n");
        return head;
    }
    if(!prev)
        head=head->next;
    else
        prev->next=cur->next;
    free(cur);
    return head;
}
int main()
{
    struct tnode *head=dodaj_na_poczatek(NULL,23);
    head=dodaj_na_poczatek(head,13);
    head=dodaj_na_poczatek(head,67);
    head=dodaj_na_poczatek(head,3);
    head=dodaj_na_poczatek(head,123);
    printf("Lista po dodaniu na poczatek:\n");
    printList(head);
    head=wyczysc(head);
 
    dodaj_na_koniec(&head,23);
    dodaj_na_koniec(&head,13);
    dodaj_na_koniec(&head,67);
    dodaj_na_koniec(&head,3);
    dodaj_na_koniec(&head,123);
    printf("\nLista po dodaniu na koniec:\n");
    printList(head);
    head=wyczysc(head);
 
    head=dodaj_do_posortowanej(head,23);
    head=dodaj_do_posortowanej(head,13);
    head=dodaj_do_posortowanej(head,67);
    head=dodaj_do_posortowanej(head,3);
    head=dodaj_do_posortowanej(head,123);
    printf("\nLista po dodaniu posortowanych:\n");
    printList(head);
    printf("Po usuneciu 67:\n");
    head=usun(head,67);
    printList(head);
    printf("Proba usuniecia 100:\n");
    head=usun(head,100);
    printf("Szukanie 123:\n");
    szukaj(head,123);
    printf("Szukanie 122:\n");
    szukaj(head,122);
    head=wyczysc(head);
    return 0;
}
