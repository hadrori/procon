#include "stdio.h"

int main(void){

  //int pd[64] = {0};
  int num = 2520;
  int i, j, k, l;
  int flag = 1;
  while( flag){
    num++;
    for( i = 1; i < 21; i++){
      if( num % i == 0){
      }else{
	break;
      }
      if( i == 20){
	flag = 0;
      }
    }

  }
  /*
  for( i = 2; i <=20; i++){
    for( j = 2; j <= i; j++){
      k = 0;
      l = i;
      while( l % j == 0){
	k++;
	l /= j;
	if(k > pd[j]){
	  pd[j] = k;
	} 
      }
    }
  }
  for( i = 2; i <= 20; i++){
    while( pd[i] > 0){
      num *= i;
      pd[i]--;
    }
  }
  */
  printf("%d\n", num);
  return 0;
}
