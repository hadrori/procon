/*
 保留
 オイラーφ関数を再帰的に求めればよさそう
 */

#include <iostream>
#include <cmath>

#define ll long long int

using namespace std;

int primes[100000] = {0};

ll EulerSum(ll n, ll k);

ll mrand(){
    srand((ll)time(NULL));
    return rand();
}

bool prime_judge( ll n);

void make_prime(){
    
    primes[0] = 2;
    int cnt = 1;
    for( int i = 3; i < 5000; i += 2){
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
    
    for( ll j = 5001; j < 1000000; j += 2){
        if( prime_judge( j)){
            primes[cnt++] = j;
        }
    }
    
    return;
}


int main(){
    
    ll ans = 0;
    
    make_prime();
    
    ans = EulerSum( 1000000, 0) - 1;

    cout << ans << endl;
    
    return 0;
}

ll EulerSum( ll n, ll k){
    ll sum = 1;

    for( ll i = k; primes[i] <= n; i++){
        ll m = n;
        ll q = primes[i];
        
        while( m >= primes[i]){
            m /= primes[i];
            sum += q * ( primes[i] - 1) / primes[i] * EulerSum( m, k + 1);
            q *= primes[i];
        }
    }
    
    return sum;
}

bool prime_judge( ll n){
    
    if( n == 2){
        return true;
    }
    ll d = n - 1;
    ll s = 0;
    
    while( d % 2 == 0){
        d /= 2;
        s++;
    }
    for( int k = 0; k < 15; k++){
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