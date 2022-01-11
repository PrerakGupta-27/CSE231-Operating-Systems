#include <stdio.h>

extern void B();

void A(){

  long long int var = 97;
  
  B(var);

}

int main(void) {
  A();
}