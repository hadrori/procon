#include "stdio.h"

int main(void){

  int nums[20];
  int numis[20];

  int i = 19;


  for( i = 0; i < 1000000; i++){
    if( i % 19 == 0){
      printf("%d\n", i);
    } 
  }
  return 0;

}
