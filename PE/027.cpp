#include <iostream>
#define ll long long int

using namespace std;

int primes[100000];
int checkp[100000] = {false};

void make_prime(){
    
    primes[0] = 2;
    checkp[2] = true;
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
            checkp[primes[cnt-1]] = true;
        }
    }
    
    return;
}

int main(){
    
    make_prime();
    int a = 0;
    int b = 3;
    ll ans = 0;
    int maxn = 0;
    for( a = -999; a < 1000; a++){
        for( b = -999; b < 1000; b++){
            int j = b;
            if( j < 0){
                j *= -1;
            }
            if( checkp[b]){
                int n = 0;
                bool mflag = false;
                while(1){
                    int t = n * n + a * n + b;
                    if( !checkp[t]){
                        break;
                    }
                    n++;
                    if( maxn < n){
                        maxn = n;
                        mflag = true;
                    }
                }
                if(mflag){
                    ans = a * b;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}