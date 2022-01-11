#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{   int data;
    struct node* next;
};
struct node* front;
struct node* rear;

struct node* constructor(int n){

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;

    return temp;

}

void enqueue(int d){

    struct node* temp = constructor(d);
    if(front==NULL){
        front = temp;
        rear = temp;
        return;
    } 
    rear->next = temp;
    rear = temp;
}

void dequeue(){

    if(front==NULL)return;
    if(front==rear){
        front = NULL;
        rear = NULL;
        return;
    }
    struct node* temp = front;

    front = front->next;
    temp->next = NULL;
    free(temp);
}

void print_q(){

    if(front==NULL)return;
    struct node* it = front;
    while (it!=NULL)
    {
        printf("%d ",it->data);
        it=it->next;
    }
    printf("\n");
}

int main(){

    front=NULL;
    rear=NULL;
    int e ;
    printf("enter 1 for enqueue\nenter 2 for dequeue\n");
    scanf("%d ",&e);

    while(e!=-1){

        if(e==1){

            int v;
            printf("enter the no :");
            scanf("%d",&v);
            enqueue(v);
        }
        else if(e==2)dequeue();

        print_q();
        printf("enter 1 for enqueue\nenter 2 for dequeue\n");
        scanf("%d",&e);

    }
    return 0;
}
