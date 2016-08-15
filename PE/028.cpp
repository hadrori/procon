#include <iostream>

#define NUM 1001

using namespace std;

int main(){

  long int sum = 1;
  long int back = 1;
  for( int i = 1; i <= ( NUM - 1) / 2; i++){
    for(int j = 0; j < 4; j++){
      back += i * 2;
      sum += back;
    }
  }

  cout << sum << endl;
  return 0;
}
