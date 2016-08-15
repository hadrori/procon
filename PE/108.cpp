#include <iostream>

#define ll long long int

using namespace std;

int main(){
    int cnt = 0;
    ll n = 2;
    while( cnt <= 1000){
        n++;
        ll n2 = n * n;
        cnt = 0;
        for( ll j = 1; j <= n; j++){
            if( n2 % j == 0){
                cnt++;
            }
        }
    }

    cout << n << endl;
    
    return 0;
}

/*
1/x + 1/y = 1/n
 
y = n + n^2/x-n
 
解の数が1000を超える最小のn
*/