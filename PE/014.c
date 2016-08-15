#include "stdio.h"

int main(void){
  long int i = 0;
  int max = 0;
  long int mnum;
  for( i = 500000; i < 1000000; i++){
    long int num = i;
    int count = 1;
    while( num > 1){
      count++;
      if( num % 2 == 0){
	num /= 2;
      }else{
	num = num * 3 + 1;
      }
    }
    if( count > max){
      max = count;
      mnum = i;
    }
  }

  printf("%ld\n", mnum);

  return 0;
}
