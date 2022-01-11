#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct matrix
{
    int* col;
};

void print(struct matrix* row, int r , int col[]){

    for( int i = 0 ; i<r ; i++ ){
        for(int j = 0; j<col[i] ; j++){
            printf("%d ",row[i].col[j]);
        }
        printf("\n");
    }
}

int main(){
    
    printf("Enter the no of rows ");
    int r ; 
    scanf("%d",&r);

    struct matrix* row = calloc(r,sizeof(struct matrix));

    int col[r];
    for( int i = 0 ; i<r ; i++){
        int c ;
        printf("Enter the no colums for row %d ",i+1);
        scanf("%d",&c);
        col[i]=c;
        row[i].col = calloc(c , sizeof(int));
    }

    print(row,r,col);

    printf("enter the row no whose colums u want to change ");
    int a,b;
    scanf("%d",&a); a--;
    printf("enter the new size of coulumn ");
    scanf("%d",&b);
    col[a]=b;
    row[a].col = realloc( row[a].col, b*sizeof(int));

    print(row,r,col);
    printf("%d",row[3].col[10]);
    return 0;
    
}

