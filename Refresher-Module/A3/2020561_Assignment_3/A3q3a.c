#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{   int data;
    struct node* left;
    struct node* right;
};

struct node* constructor(int n){

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

}


struct node* insert(struct node* root,int data){

    if(root==NULL){
       root= constructor(data);
    }
    else if(data<root->data)
        root->left=insert(root->left,data);
    else 
        root->right=insert(root->right,data);

    return root;
}

int min(struct node* root){
    if(root==NULL)
        return -1;
    while (root->left!=NULL)
        root=root->left;
    return root->data;
}

struct node* delete_node(struct node* root, int data){

    if(root==NULL)
        return  root;

    if(data<root->data)
        root->left=delete_node(root->left,data);
    else if(data>root->data)
        root->right=delete_node(root->right,data);
    else{

        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            int d = min(root->right);
            root->data=d;
            root->right= delete_node(root->right,d);
        }
    }
    return root;
}
void inorder(struct node* root){
    if(root==NULL)return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);

}
struct node* root;
int main(){

    root = NULL;
    int e;
    scanf("%d",&e);

    while (e!=-1)
    {
        if(e==1){
            int v; 
            scanf("%d",&v);
            root= insert(root,v);
        }
        else if(e==2){
            int v; 
            scanf("%d",&v);
            root=delete_node(root,v);
        }

        inorder(root);
        printf("\n");

        scanf("%d",&e);
    }
    

    return 0;
}