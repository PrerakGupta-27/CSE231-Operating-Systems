#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct matrix
{
    int* col;
};

int main(){

    struct matrix* row = malloc(6*sizeof(struct matrix));

    row[0].col = malloc(7*sizeof(int));
    row[1].col = malloc(4*sizeof(int));
    row[2].col = malloc(6*sizeof(int));
    row[3].col = malloc(3*sizeof(int));
    row[4].col = malloc(7*sizeof(int));
    row[5].col = malloc(2*sizeof(int));

    int col[] ={ 7,4,6,3,7,2};

    for( int i = 0 ; i< 6 ; i++){

        for (int j = 0 ; j< col[i] ; j++){

            row[i].col[j] = j;
            printf("%d ",row[i].col[j]);

        }
        printf("\n");
    }
    printf("%d",row[5].col[3]);
    return 0;
}
