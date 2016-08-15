#include "stdio.h"

int main(void){

  int i, j;
  int digit[1000] = {0};
  digit[0] = 1;
  int max = 1;
  for( i = 1; i < 101; i++){
    for( j = 0; j < max; j++){
      digit[j] *= i;
    }
    for( j = 0; j < max + 2; j++){
      if( digit[j] / 10 > 0){
	digit[j+1] += digit[j] / 10;
	digit[j] %= 10;
	if( j + 1 == max){
	  max++;
	}
      }
    }
  }
  int sum = 0;
  for( i = 0; i < max; i++){
    sum += digit[i];
  }
  printf("%d\n", sum);
  return 0;
}
