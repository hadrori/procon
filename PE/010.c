#include "stdio.h"

int main(void){

  int i, j;
  long int pd[1000000];
  pd[0] = 2;
  long int max = 1;
  long int sum = 2;
  for( i = 3; i < 2000000; i++){
    int flag = 1;
    for( j = 0; j < max; ++j){
      if( i % pd[j] == 0){
	flag = 0;
	break;
      }else{
	flag = 1;
      }
    }
    if( flag == 1){
      pd[max++] = i;
      sum += i;
    }
  }

  printf("%ld %ld %ld\n", max, pd[max-1],sum);
  return 0;
}
