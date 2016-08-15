#include "stdio.h"

int main(void){

  long int primes[100000];
  primes[0] = 2;
  int max = 1;
  int i = 3, j;
  while(primes[max] < 1000000){
    int flag = 1;
    for( j = 0; j < max; j++){
      if( i % primes[j] == 0){
	flag = 0;
	break;
      }
    }
    if( flag == 1){
      primes[max++] = i;
      //printf("%ld", primes[max-1]);
    }
    i++;
  }

  i = 0;
  long int ans = 0;
  long int sum = 0;
  while(1){
    //printf("aa\n");
    sum += primes[i];
    j = 0;
    while( primes[j] <= sum){
      if( primes[j] == sum){
	ans = sum;
	break;
      }
      j++;
    }
    if( sum > 1000000){
      break;
    }
    i++;
  }

  printf("%ld\n", ans);
  return 0;
}
