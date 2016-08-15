#include <iostream>

#define ll long long int
using namespace std;


int main(){

  ll ym = 1;
  ll xm = 1;
  ll n = 0;
  ll b = 0;
  while( n < 1000000000000){
    ll tmpy = ym;
    ym = 2 * xm + 3 * ym;
    xm = 3 * xm + 4 * tmpy;
    n = ( xm + 1) / 2;
    b = ( ym + 1) / 2;
  }

  cout << b << endl;
  return 0;
}
