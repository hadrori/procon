#include "stdio.h"

int main(void){

  int primes[5000];
  primes[0] = 2;
  int max = 1;
  int i = 3, j, k;
  while(max < 5000){
    int flag = 1;
    for( j = 0; j < max; j++){
      if( i % primes[j] == 0){
	flag = 0;
	break;
      }
    }
    if( flag == 1){
      primes[max++] = i;
    }
    i++;
  }
  int sum = 0;
  int cmp[5000] = {0};
  int l = 0;
  for( i = 1; i <= 10000; i++){
    int sumt = 0;
    for( j = 1; j < i / 2 + 1; j++){
      if( i % j == 0){
	sumt += j;
      }
    }
    int sumt2 = 0;
    for( j = 1; j < sumt / 2 + 1; j++){
      if( sumt % j == 0){
	sumt2 += j;
      }
    }

    if( i == sumt2 && i != sumt){
      sum += i;
      printf("%d %d %d\n", i, sumt, sumt2);
    }
  }

  printf("%d\n", sum);
  return 0;
}
