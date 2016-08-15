#include "stdio.h"

int main(void){

  int a, b, c;
  int ans = 0;
  for( a = 1; a < 333; a++){
    for( b = a + 1; b < ( 1000 - a) / 2; b ++){
      c = 1000 - a - b;
      int asumb = a * a + b * b;
      if(asumb == c * c){
	ans = a * b * c;
	break;
      }
    }
    if(ans > 0){
      break;
    }
  }

  printf("%d %d %d %d\n", a, b, c, ans);

  return 0;
}
