#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int next_carry(int d){

    if(d%2==0)return 0;
    return 5;
}

char odd_even(int d){
    if(d%2==0)return '0';
    return '1';
}

char* divide_2(char a[]){

    char *ans= malloc(sizeof(char)*1000);
    int j=0;

    while ( strlen(a)>0){

        int n = strlen(a);

        int l = a[n-1] - '0';
        ans[j++] = odd_even(l);
        
        int c = 0;
        for(int i = 0 ; i<n ; i++){

            int d = a[i] - '0';
            a[i]= d/2 + c +'0';
            c = next_carry(d);
        }
  
        char b[1000];
        int i = 0;
        int f = 0;
        for(int k =0 ; k< n ; k++){

            if(a[k]=='0' && f==0)continue;
            f=1;
            b[i]=a[k];
            i++;
        }
        b[i]='\0';
        strcpy(a,b);
    }

    ans[j]='\0';
    
    return ans;
}

char add_2_bits(char a, char b,char c){

    int x = a-'0';
    int y = b-'0';
    int z = c-'0';
    return (x+y+z)%2+'0';
   
}

char carry(char a , char b, char c){

    int x = a-'0';
    int y = b-'0';
    int z = c-'0';
    if(x+y+z >1 ) return '1';
    return '0';
}

void Add(char* A , char* B , int n ){

    char* ans = malloc(sizeof(char)*1000);
    
    char c = '0';
    int i;
    for(  i = 0 ; i< n  ; i++){
    
        ans[i]=add_2_bits(A[i],B[i],c);
        c=carry(A[i],B[i],c);
    }
    printf("the sum of both the no is : ");
    ans[i]=c;
    ans[++i]='\0';
    n = strlen(ans);
    for(int i = 0 ; i<n ; i++)
        printf("%c",ans[n-i-1]);
}

int main() {

    char a[1000];
    char b[1000];

    printf("enter the first no : ");
    scanf("%s",a);
    printf("enter the sencond no : ");
    scanf("%s",b);
    char *A =divide_2(a);
    char *B = divide_2(b);
  
    int sa=strlen(A);
    int sb=strlen(B);
    int i=0;
    if(sa>sb){
        for( i =sb ; i<sa ; i++)
            B[i]='0';
        B[i]='\0';
    }else{
        for( i =sa ; i<sb ; i++)
            A[i]='0';
        A[i]='\0';
    }
    printf("\nbinary form of a is : ");
    int n = strlen(A);
    for(int i = 0 ; i<n ; i++)
        printf("%c",A[n-i-1]);

    printf("\nbiary forn of b is : ");
    for(int i = 0 ; i<n ; i++)
        printf("%c",B[n-i-1]);

    printf("\n");
    Add(A,B,n);

  return 0;
}
