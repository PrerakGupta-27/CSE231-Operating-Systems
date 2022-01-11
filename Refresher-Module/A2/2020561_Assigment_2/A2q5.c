#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void swap_AB(int *a, int *b){

    int temp = *a;
    *a=*b;
    *b=temp;  
}

void bubble_sort(int a[], int n){

    for(int i = 0 ; i<n ;i++ ){

        int s = 0;

        for(int j=0; j<n-i-1 ; j++){

            if(a[j]>a[j+1]){
                swap_AB(&a[j],&a[j+1]);
                s++;
            }
        }
        if(s==0)break;
    }
}

void selection_sort(int a[],int n){
    

    for(int i =0 ; i<n ; i++){

        int m=a[i];
        int p=i;

        for(int j =i+1 ; j<n ; j++){
            if(a[j]<m){
                m=a[j];
                p=j;
            }
        }
        if(p!=i)swap_AB(&a[p],&a[i]);
    }
}

int main(){

    int n;
    printf("enter the size of the array ");
    scanf("%d",&n);

    int* a = malloc(n*sizeof(int));

    printf("enter the elements\n");
    for(int i =0; i<n ; i++){
        scanf("%d",&a[i]);
    }

    int c;
    printf("enter 1 for bubble sort 2 for selection sort");
    scanf("%d",&c);

    if(c==1)bubble_sort(a,n);
    else if(c==2)selection_sort(a,n);
    else{
        printf("wrong input");
        exit(0);
    }
    for(int i = 0 ; i<n; i++){
        printf("%d ",a[i]);
    }

    return 0;
}