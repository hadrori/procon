#include <iostream>

using namespace std;

int main(){

  int max = 1;
  int ans = 2;
  for( int i = 2; i <= 1000; i++){
    long int num = 1;
    int digits[1000] = {0};
    int asdf[1000] = {0};
    asdf[0] = 1;
    int j = 0;
    bool mflag = true;
    while(mflag){

      while( num < i){
	num *= 10;
	j++;
      }

      if( num % i == 0){
	mflag = false;
	break;
      }
      digits[j] = num / i;
      asdf[j] = num % i;
      num %= i;
 
      for( int k = j - 1; k >= 0; k--){
	if( asdf[j] == asdf[k]){
	  if( max < j - k + 1){
	    max = j - k;
	    ans = i;
	  }
	  mflag = false;
	  break;
	}
      }
    }
    cout << 1 << endl;
  }

  cout << ans << endl;
  return 0;
}
