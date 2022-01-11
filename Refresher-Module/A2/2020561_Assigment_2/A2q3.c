#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

void add(int a, int b){
    printf("%d\n",a+b);
}

void sub(int a, int b){
    printf("%d\n",a-b);
}

void mul(int a, int b){
    printf("%d\n",a*b);
}

void division(int a, int b){
    if(a==0)return;
    printf("%f\n",a/b);
}

void expo(int a,int b){
    printf("%f\n",pow(a,b));
}

int main(){

    void (*arr[5])(int,int);

    arr[0]=add;
    arr[1]=sub;
    arr[2]=mul;
    arr[3]=division;
    arr[4]=expo;

    printf("enter the 2 intergers : ");
    int a,b;
    scanf("%d%d",&a,&b);

    arr[0](a,b);
    arr[1](a,b);
    arr[2](a,b);
    arr[3](a,b);
    arr[4](a,b);

    return 0;
}