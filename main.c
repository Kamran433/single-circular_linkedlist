#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*first,*second,*third;
void Pri(struct Node* p){
    printf("The entries are : ");
    while(p!=NULL){
        printf("%d",p->data);
        p = p->next;
    }}
int count(struct Node* p){
    int c=0;
    while(p!=NULL){
        p=p->next;
        c++;
    }
    return c;
}
void Insert(struct Node* p,int index,int x){
    struct Node* n;
    
    n = (struct Node*)malloc(sizeof(struct Node));

    if(index<0||index>count(p)){
        return;
    }
    
    if (index ==0){
    n->data = x;
    n->next = first;
        first = n;}
        else{
            for(int i = 0;i<index-1;i++){
                p=p->next;
            }
            n->next=p->next;
            p->next =n;
            n->data=x;
    }
}
void insertend(struct Node* p,int x){
    struct Node* q;
    q = (struct Node*)malloc(sizeof(struct Node));
    q->data = x;
    q->next = NULL;
    for(int i = 0;i<count(p)+1;i++){
        p=p->next;
    }
    p->next = q;
}
void del(struct Node* p,int index){
    struct Node *q=NULL;
    if(index<0||index>count(p)){
        return;
    }
    if(index==1){
        q=first;
        first = first->next;
        free(q);
    }
    else{
    for(int i = 0;i<index-1;i++){
        q=p;
        p= p->next;
    }
    q->next=p->next;
        free(p);}
    printf("\nkey deleted was = %d\n",p->data);
}
void clist(struct Node* p){
    struct Node* q=NULL;
    q = (struct Node*)malloc(sizeof(struct Node));
    q->next=first;
    for(int i = 0;i<count(p)+1;i++){
        p=p->next;
    }
    p->next = q->next;
    free(q);

}
int main(){
first = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
third = (struct Node*)malloc(sizeof(struct Node));
first->data = 2;
first->next = second;
second->data = 4;
second->next = third;
third->data = 6;
third->next = NULL;
//Insert(first,2,8);
insertend(first,1);
//Pri(first);
//printf("\nThe number of entries = %d",count(first));
del(first,1);
Insert(first,2,8);
//clist(first);
Pri(first);
printf("\nThe number of entries = %d\n",count(first));
return 0;}
