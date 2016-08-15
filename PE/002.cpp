#include <iostream>

int main(){

  int a = 1, b = 1;
  int t = 0;
  int sum = 0;
  while( b < 4000000){
    t = b;
    b += a;
    a = t;
    if( b % 2 == 0){
      sum += b;
    }
  }
    cout << "Answer : " << sum << endl;
  return 0;
}
