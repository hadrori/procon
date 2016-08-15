#include "stdio.h"

int main(void){

  unsigned long int a;
  long int i;
  a = 1;

  for( i = 10; i < 20; i++){
    a *= 2 * (i + 1) - 1;
  }
  for( i = 0; i < 10; i++){
    a /= (i + 1);
    a *= 2;
  }
  printf("%ld\n", a);
  return 0;
}
