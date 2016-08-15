#include "stdio.h"

int main(void){
  int a = 999;
  int b = 999;
  long int n;
  long int k = 0;
  int pd[ 10];
  int i = 0;
  for( b; b > 0; b--){
    for( a; a > 0; a--){
      n = a * b;
      if( n > k){
	long int t = n;
	for( i = 0; t > 0; i++){
	  pd[ i] = t % 10;
	  t /= 10;
	}
	for(int j = 0; ; j++){
	  if(pd[ i-1 - j] != pd[ j]){
	    break;
	  }else if( ( i % 2 == 1 && j == (i + 1) / 2) || j == i / 2){
	    if( n > k){
	      k = n;
	    }
	    break;
	  }
	}
      }
    }
    a = 999;
  }

  printf("%ld\n", k);
  return 0;
}
