#include "stdio.h"

int main(void){
  long int p[20000];
  p[0] = 2; 
  p[1] = 3;
  p[2] = 5;
  p[3] = 7;
  p[4] = 11;
  p[5] = 13;
  long int num = 16;
  int k = 6;
  while( k < 10001){
    int i = 0;
    int flag = 1;
    num++;
    for( ; i < k; i++){
      if( num % p[i] == 0){
	flag = 0;
	break;
      }
    }
    if( flag == 1){
      p[k++] = num;
    }

  }
  printf("%ld\n", p[10000]);
  return 0;
}
