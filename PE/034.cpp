#include <iostream>

using namespace std;

int fact( int num){
  if( num <= 1){
    return 1;
  }
  return num * fact( num-1);
}

int main(){

  long int ans = 0;
  for( long int i = 3; i < 2903040; i++){
    long int tmp = i;
    int ary[8] = {0};
    int cnt = 0;
    while( tmp > 0){
      ary[cnt++] = tmp % 10;
      tmp /= 10;
    }
    long int sum = 0;
    for( int j = 0; j < cnt; j++){
      sum += fact(ary[j]);
    }
    if( i == sum){
      ans += i;
    }
  }

  cout << ans << endl;
  return 0;
}
