#include "stdio.h"
#include "math.h"

int my_power(int x, int y);
int main(void){
  int ssum = 0;
  int sums = 0;

  for(int i = 1; i <= 100; i++){
    ssum += my_power( i, 2);
    sums += i;
  }
  sums = my_power( sums, 2);

  printf("%d\n", sums - ssum);
}

int my_power(int x, int y){

  int s = 1;
  for(int i = 0; i < y; i++){
    s *= x;
  }

  return s;
}
