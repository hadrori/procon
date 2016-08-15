#include <iostream>
#include <cmath>

#define ll long long int

using namespace std;

int primes[100000] = {0};

void make_prime(){
    
    primes[0] = 2;
    int cnt = 1;
    for( int i = 3; i < 100000; i++){
        bool pflag = true;
        for( int j = 0; j < cnt; j++){
            if( i % primes[j] == 0){
                pflag = false;
                break;
            }
        }
        if(pflag){
            primes[cnt++] = i;
        }
    }
    
    return;
}

int main(){
    
    make_prime();
    ll cnt = 0;
    
    long double t = 1.0 / 3.0;
    long double u = 1.0 / 2.0;
    
    for( ll n = 5; n <= 12000; n++){
        int j = 0;
        int pf[100000] = {0};
        int cn = 0;
        while( primes[j] <= n){
            if( n % primes[j] == 0){
                pf[cn++] = primes[j];
            }
            j++;
        }
        for( ll d = n / 3 + 1; d <= ( n - 1) / 2 ; d++){
            bool cflag = true;
            for( int i = 0; i < cn; i++){
                if( d % pf[i] == 0){
                    cflag = false;
                    break;
                }
            }
                
            if( cflag){
                cnt++;
            }
        }
    }
    
    cout << cnt << endl;
    return 0;
}