#include <iostream>
#include <cmath>

using namespace std;

int main(){

  long int sum = 0;
  int d[10] = {0,1,32,243,1024,3125,7776,16807,32768,59049};

  for( long int j = 2; j < 1000000; j++){
    long int temp = j;
    long int tmp = 0;
    while( temp > 0){
      tmp += d[temp % 10];
      temp /= 10;
    }
    if(tmp == j){
      sum += j;
    }
  }


  cout << sum << endl;
  return 0;
}
