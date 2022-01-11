#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void swap_AB(int *a, int *b){

    int temp = *a;
    *a=*b;
    *b=temp;  
}


int binary_search(unsigned int v,unsigned int a[], int n){

    int l=0;
    int r=n;
    int m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if(a[m]==v)
            return m;
        else if (a[m]<v)
            l=m+1;
        else 
            r=m-1;    
    }
    return -1;
}

int main(){

    printf("enter the size of an array : ");
    unsigned int n;
    scanf("%u",&n);
    printf("enter the elements of the array :");
    unsigned int* arr  = malloc(sizeof(unsigned int));

    for(int i =0 ; i<n ; i++)
        scanf("%u",&arr[i]);
    
    printf("enter the element to search : ");
    unsigned int e;
    scanf("%u",&e);
    
    int p = binary_search(e,arr,n);
    if(p==-1)printf("element not found in the array");
    else printf("element is present at index :  %d",p);

    return 0;
}