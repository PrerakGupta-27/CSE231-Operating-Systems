#include<stdio.h>
#include<stdlib.h>

struct node
{
    int rollno;
    char name[50];
    int join;
    char program[50];
    struct node* next;

};

void constructor(struct node* a){

    printf("enter your rollno ");
    scanf("%d",&a->rollno);
    printf("enter your name ");
    scanf("%s",a->name);
    printf("enter year of joining ");
    scanf("%d",&a->join);
    printf("enter program ");
    scanf("%s",a->program);
    a->next=NULL;

}

struct node* head;

void insert(int n){

    struct node* temp = malloc(sizeof(struct node));
    constructor(temp);

    if(n==1){
        temp->next=head;
        head=temp;
        return;
    }
    
    struct node* it = head;

    for(int i =0 ; i<n-2 ; i++)
        it=it->next;

    temp->next=it->next;
    it->next=temp;

   
}
void delete_at(int n){

    if(head==NULL)return;
    struct node* it = head;
    
    if(n==1){
        head=head->next;
        free(it);
        return;
    }
    for(int i =0 ; i<n-2 ; i++)
        it = it->next;
    
    struct node* it2 = it->next;
    it->next=it2->next;
    free(it2);

}

void print_(){

    if(head==NULL)
        return;
    struct node* it = head;
    printf("Roll No    Name       join year       program \n");

    while (it!=NULL)
    {
        printf("%d        %s      %d          %s\n",it->rollno,it->name,it->join,it->program);
        it = it->next;
    }

}

int main(){

    head=NULL;
    int e ;
    printf("enter 1 to insert\nenter 2 to delete\n");
    scanf("%d ",&e);
    int v;
  
    while(e!=-1){

        if(e==1){

            printf("enter the position at which you want to insert :");
            scanf("%d",&v);
            insert(v);
        }
        else if(e==2){
            
            printf("enter the position at which you want to delete :");
            scanf("%d",&v);
            delete_at(v);
        }

        print_();
        printf("enter 1 to insert\nenter 2 to delete\n");
        scanf("%d",&e);

    }

    return 0;
}