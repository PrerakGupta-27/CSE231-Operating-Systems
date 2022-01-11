#include <stdio.h>
#define fo(i,n) for(int i =0 ; i<n ; i++)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b=temp;
}

int main(){

    unsigned int a, b;
    printf("enter value of a :");
    scanf("%u",&a);
    printf("enter value of b :");
    scanf("%u",&b);
    swap(&a,&b);
    printf("a = %u b = %u ",a,b);

    unsigned int n;
    printf("\nenter the size of the arrays : ");
    scanf("%u",&n);


    int x[n],y[n];

    printf("enter elements of array x: ");
    for(int i =0 ; i<n ; i++)
        scanf("%d",&x[i]);

    printf("enter elements of array y: ");
    for(int i =0 ; i<n ; i++)
        scanf("%d",&y[i]);

    fo(i,n)
        swap(&x[i],&y[i]);
    
    printf("elements of array x after swapping : ");
    for(int i =0 ; i<n ; i++)
        printf("%d ",x[i]);

    printf("\n");
    
    printf("elements of array y after swappint : ");
    for(int i =0 ; i<n ; i++)
        printf("%d ",y[i]);

    return 0;
}