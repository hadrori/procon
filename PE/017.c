#include "stdio.h"

int main(void){

  int i;
  int count = 0;
  int f1t9, f10t19, f20t99, f1t99, f100t999;
  f1t9 = 3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4;
  f10t19 = 3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8;
  f20t99 = f1t9 * 8 + 10 * ( 6 + 6 + 5 + 5 + 5 + 7 + 6 + 6);
  f1t99 = f1t9 + f10t19 + f20t99;
  f100t999 = f1t9 * 100 + 7 * 900 + 3 * ( 900 - 9) + 9 * f1t99;
  printf("%d\n", f100t999 + f1t99 + 11);

  return 0;
}
