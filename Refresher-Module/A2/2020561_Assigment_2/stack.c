#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{   int data;
    struct node* next;
};
struct node* head;

struct node* constructor(int n){

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;

    return temp;

}


void push(int data ){

    struct node* temp = constructor(data);
    temp->next=head;
    head=temp;

}
void pop(){

    if(head==NULL)return;
    struct node* temp =head;
    head=head->next;
    free(temp);

}
void print_stack(){

    if(head==NULL)
        return;

    struct node* it = head;

    while (it!=NULL)
    {
        printf("%d ",it->data);
        it = it->next;
    }
    printf("\n");
}


int main(){

    head=NULL;
    int e ;
    printf("enter 1 for push\nenter 2 for pop\n");
    scanf("%d ",&e);

    while(e!=-1){

        if(e==1){

            int v;
            printf("enter the no :");
            scanf("%d",&v);
            push(v);
        }
        else if(e==2)pop();

        print_stack();
        printf("enter 1 for push\nenter 2 for pop\n");
        scanf("%d",&e);

    }
    return 0;
}
