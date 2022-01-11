#include <stdio.h>
#include <string.h>
int main(){

    char a[100];
    scanf("%s",a);
    int j = strlen(a)-1;
    char str[100];
  

    for( int i = 0 ; i< (strlen(a)-1)/2 ; i++){
        char c = a[i];
        a[i] = a[j];
        a[j]= c;
        j--;
    }

    printf("%s",a);
    return 0;
}

void swap_pointers(char** a, char** b){

    char* temp = *a;
    *a=*b;
    *b = temp;

}
