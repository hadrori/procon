#include "stdio.h"

int main(void){

  int primes[500];
  primes[0] = 2;
  int max = 1;
  int i = 3, j;
  while(max < 500){
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
  int k = 1;
  while(1){
    sum += k;
    int l = 0;
    int count[500] = {0};
    while( primes[l] < sum){
      int temp = sum;
      if( sum % primes[l] == 0){
	while( temp % primes[l] == 0){
	  temp /= primes[l];
	  count[l]++;
	}
      }
      l++;
    }
    int pat = 1;
    for( i = 0; i < l; i++){
      pat *= ( count[i] + 1);
    }
    if(pat >= 500){
      break;
    }
    k++;
  }

  printf("%d\n", sum);

  return 0;
}
