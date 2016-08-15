#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define ll long long int

using namespace std;

int primes[100000] = {0};

bool prime_judge( ll n);

ll mrand(){
    srand((ll)time(NULL));
    return rand();
}


void make_prime(){
    
    primes[0] = 2;
    int cnt = 1;
    for( int i = 3; i < 10000; i++){
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
    /*
    for( ll j = 5000; j < 100000; j++){
        if( prime_judge( j)){
            primes[cnt++] = j;
        }
    }
     */
    
    return;
}


int main(){
    
    long double disp = 1000;
    long double t = 3.0 / 7.0;
    int ans = 0;
    make_prime();
    cout << ans << endl;
    
    for( int n = 1000000; n >= 990000; n--){
        for( int d = (double)n * 0.45; d > (double)n * 0.4 ; d--){
            if( n % 2 != 0 || d % 2 != 0){
                long double tmp = (long double)d / (long double)n;
                if( t > tmp){
                    //cout << 'A' << endl;
                    if( t - tmp < disp){
                        //cout << 'B' << endl;
                        int j = 0;
                        bool cflag = true;
                        //cout << ans << endl;
                        while( primes[j] <= sqrt(n) && primes[j] <= d){
                            if( d % primes[j] == 0 && n % primes[j] == 0){
                                cflag = false;
                                break;
                            }
                            j++;
                        }
                        //cout << ans << endl;
                        if( cflag){
                            disp = t - tmp;
                            ans = d;
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

bool prime_judge( ll n){
    
    if( n == 2){
        return true;
    }
    if( n % 2 == 0){
        return false;
    }
    ll d = n - 1;
    ll s = 0;
    
    while( d % 2 == 0){
        d /= 2;
        s++;
    }
    for( int k = 0; k < 20; k++){
        ll a = mrand() % ( n - 1 );
        ll ad = 1;
        for( int i = 0; i < d; i++){
            ad = (ad * a) % n;
        }
        bool flag = true;
        if( ad != 1){
            for( int r = 0; r <= s - 1; r++){
                ll ard = 1;
                for( int i = 0; i < pow( 2,(double)r) * d; i++){
                    ard = ( ard * a) % n;
                }
                if( ard == n - 1){
                    flag = false;
                    break;
                }
            }
            if( flag){
                return false;
            }
        }
    }
    return true;
}