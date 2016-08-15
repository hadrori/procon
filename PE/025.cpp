#include <iostream>
#include <cstdlib>

using namespace std;

int a[1000] = {0};
int b[1000] = {0};
int term = 0;
int digits = 1;


void mfib(){
  bool carryFlag = false;

  int temp[1000] = {0};
  int carrys[1000] = {0};
  int i;
  for( i = 0; i < digits; i++){

    temp[i] = a[i];
    a[i] = b[i];
    b[i] += temp[i] + carrys[i];
    if( b[i] >= 10){
      b[i] %= 10;
      if( i + 1 == digits){
	b[i+1]++;
	carryFlag = true;
      }else{
	carrys[i+1]++;
      }
    }
  }

  if(carryFlag){
    digits++;
  }

  term++;

  return;
}

int main(){

  a[0] = 1;
  b[0] = 1;
  term = 2;

  while( digits < 1000){
    mfib();
  }
  cout << term << endl;
  return 0;
}
