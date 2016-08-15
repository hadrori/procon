#include <iostream>
#include <cmath>

int main(){
  long int num = 600851475143;
  
  long int t = sqrt(num);
  long int p = 0;

  for( long int i = 2; i < t; i++){
    if( num % i == 0){
      num /= i;
      while( num % i == 0){
	num /= i;
      }
      p = i;
      t = sqrt(num);
    }
  }
  if( p > num ){
    cout << "Answer : " << p << endl;
  }else{
    cout << "Answer : " << num << endl;
  }

  return 0;
}
