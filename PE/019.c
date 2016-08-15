#include "stdio.h"

int main(void){

  int y = 1901, m = 1, d = 1;
  int counting = 365;
  int num = 0;

  for(; y < 2001; y++){
    m = 1;
    for(; m < 13; m++){
      d = 1;
      while(1){
	counting++;
	if( d == 1 && counting % 7 == 0){
	  num++;
	}
	if( m == 4 || m == 6 || m == 9 || m == 11){
	  if( d == 30){
	    break;
	  }
	}else if( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
	  if( d == 31){
	    break;
	  }
	}else {
	  if( y % 4 != 0 || ( y % 100 == 0 && y % 400 != 0)){
	    if( d == 28){
	      break;
	    }
	  }else{
	    if( d == 29){
	      break;
	    }
	  }
	}
	d++;
      }
    }
  }

    printf("%d\n", num);
    return 0;
}
