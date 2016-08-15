#include <iostream>

#define NUM 10

using namespace std;

long int fact(int n){
  if( n < 2){
    return 1;
  }else{
    return n * fact(n-1);
  }
}

int main(){

  long int number = 1000000;
  bool nflag[10] = {false};
  int nums[10] = {0};

  for( int i = 0; i < NUM; i++){
    long int temp = fact( NUM - i - 1);
    for( int j = 0;; j++){
      if( temp * ( j + 1) >= number){
	number -= temp * j;
	int k = 0;
	int cnt = 0;
	while(true){
	  if( nflag[k] == false){
	    if( cnt == j){
	      nums[i] = k;
	      cout << k << endl;
	      nflag[k] = true;
	      break;
	    }
	    cnt++;
	  }
	  k++;
	}
	break;
      }
    }
  }

  for( int i = 0; i < NUM; i++){
    cout << nums[i];
  }
  cout << endl;

  return 0;
}
