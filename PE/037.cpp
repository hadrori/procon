#include <iostream>
#include <cmath>

using namespace std;

int primes[1000000] = {0};
int cnt = 0;

void make_prime(){
    
    primes[0] = 2;
    cnt = 1;
    for( int i = 3; i < 1000000; i++){
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
    int ansc = 0;
    int sum = 0;
    
    for( int i = 0; ansc < 11; i++){
        if( primes[i] > 10){
            bool cflag = true;
            int digs[10] = {0};
            int tmp = primes[i];
            int cc = 0;
            while( tmp > 0){
                digs[cc++] = tmp % 10;
                tmp /= 10;
            }
            
            for( int j = 1; j < cc; j++){
                int num = 0;
                for( int k = 0; k < j; k++){
                    num += digs[k] * pow( 10, (double)k);
                }
                if( num == 1){
                    cflag = false;
                    break;
                }
                for( int k = 0; primes[k] < num; k++){
                    if( num % primes[k] == 0){
                        cflag = false;
                        break;
                    }
                }
                if( !cflag){
                    break;
                }
                num = 0;
                for( int k = cc - j; k < cc; k++){
                    num += digs[k] * pow( 10, (double)( k - cc + j));
                }
                if( num == 1){
                    cflag = false;
                    break;
                }
                for( int k = 0; primes[k] < num; k++){
                    if( num % primes[k] == 0){
                        cflag = false;
                        break;
                    }
                }
                if( !cflag){
                    break;
                }
            }
            
            if( cflag){
                sum += primes[i];
                cout << primes[i] << " " << i << endl;
                ansc++;
            }
        }
    }
    
    cout << sum << endl;
    return 0;
    
}