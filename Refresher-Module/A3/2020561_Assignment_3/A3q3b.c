#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

struct node
{   int data;
    int h;
    struct node* left;
    struct node* right;
};

struct node* constructor(int n){

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->h=0;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

}
int height(struct node* A){
    if(A==NULL)
        return -1;
    return A->h;
}
int max(int a , int b){
    if(a>b)return a;
    return b;
}
int height_difference(struct node* A){
    if(A==NULL)
        return 0;
    return height(A->left)-height(A->right);
}
struct node* rotate_right(struct node* A){
    struct node* temp = A->left;
    A->left=temp->right;
    temp->right=A;

    A->h=max(height(A->left),height(A->right))+1;
    temp->h=max(height(temp->left),height(temp->right))+1;
    return temp;
}
struct node* rotate_left(struct node* A){
    struct node* temp = A->right;
    A->right=temp->left;
    temp->left=A;
    A->h=max(height(A->left),height(A->right))+1;
    temp->h=max(height(temp->left),height(temp->right))+1;
    return temp;
}
struct node* insert(struct node* root,int d){

    if(root==NULL){
       root= constructor(d);
    }
    else if(d<root->data)
        root->left=insert(root->left,d);
    else 
        root->right=insert(root->right,d);

    root->h = max(height(root->left),height(root->right))+1;

    int b = height_difference(root);
    if(b>1){
        if(d<=root->left->data)
            root=rotate_right(root);
        else{
            root->left=rotate_left(root->left);
            root=rotate_right(root);
        }
    }
    if(b<-1){
        if(d>root->right->data)
            root=rotate_left(root);
        else{
            root->right=rotate_right(root->right);
            root=rotate_left(root);
        }
    }

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

    root->h=max(height(root->left),height(root->right))+1;
    int b = height_difference(root);

    if(b>1){
        if(height_difference(root->left)>=0)
            root= rotate_right(root);
        else{
            root->left=rotate_left(root->left);
            root=rotate_right(root);
        }
    }
    if(b<-1){
        if(height_difference(root->right)<=0)
            root=rotate_left(root);
        else{
            root->right=rotate_right(root->right);
            root = rotate_left(root);
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
    root= NULL;
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