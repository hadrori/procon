#include <iostream>

#define ll long long int

using namespace std;

void make_primes( ll* primes);


int main(){

    int fac[4][5] = {0};
    bool cflag = false;
    
    ll primes[1000000] = {0};
    make_primes( primes);
    
    int i = 10000;
    int cnt = 0;
    
    while(1){
        i++;
        bool fflag = false;
        int c = 0;
        for( int j = 0; primes[j] < i; j++){
            if( i % primes[j] == 0){
                fac[cnt][c++] = primes[j];
            }
            if( c > 4){
                break;
            }
        }
        if( c != 4){
            cnt = -1;
            for( int a = 0; a < 4; a++){
                for( int b = 0; b < 5; b++){
                    fac[a][b] = 0;
                }
            }
        }else{

            for( int a = 0; a < cnt-1; a++){
                for( int b = a + 1; b < cnt; b++){
                    for( int d = 0; d < 4; d++){
                        for( int e = 0; e < 4; e++){
                            if( fac[a][d] == fac[b][e]){
                                fflag = true;
                            }
                            if(fflag){
                                break;
                            }
                        }
                        if(fflag){
                            break;
                        }
                    }
                    if(fflag){
                        break;
                    }
                }
                if(fflag){
                    break;
                }
            }
            if(fflag){
                cnt = -1;
                for( int a = 0; a < 4; a++){
                    for( int b = 0; b < 5; b++){
                        fac[a][b] = 0;
                    }
                }
            }
        }
        if( cnt == 3){
            break;
        }
        cnt++;
    }
    
    cout << i - 3 << endl;
    return 0;
}



void make_primes( ll* primes){
    
    primes[0] = 2;
    int cnt = 1;
    for( int i = 3; i < 200000; i++){
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
