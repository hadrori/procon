#include "stdio.h"

int main(void){

  int nums[1000] = {0};
  nums[0] = 1;
  int i, j;
  int digit = 1;
  for( i = 0; i < 1000; i++){
    int flag = 0;
    for( j = 0; j < digit; j++){
      nums[j] *= 2;
    }
    for( j = 0; j < digit; j++){
      if( nums[j] >= 10){
	nums[j + 1] += nums[j]/ 10;
	nums[j] %= 10;
	if( j + 1 >= digit){
	  flag = 1;
	}
      }
    }
    if(flag == 1){
      digit++;
    }
  }
  int sum = 0;
  for( i = 0; i < digit; i++){
    sum += nums[i];
  }
  printf("%d %d\n", digit, sum);
  return 0;
}
