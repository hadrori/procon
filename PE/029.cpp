#include <iostream>
#include <cmath>

using namespace std;

int primes[50];

void make_prime(){

    primes[0] = 2;
    int cnt = 1;
    for( int i = 3; i < 200; i++){
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
    int seq[200][10] = {0};
    
    for( int i = 2; i < 101; i++){
        int cnt = 0;
        for( int j = 0; primes[j] <= i; j++){
            if( i % primes[j] == 0){
                cnt++;
                seq[i][0] *= 100;
                seq[i][0] += primes[j];
                int tmp = i;
                while( tmp % primes[j] == 0){
                    seq[i][cnt]++;
                    tmp /= primes[j];
                }
            }
        }
    }
    bool f[200][200] = {false};
    int ans = 0;
    for( int i = 2; i < 101; i++){
        for( int j = 2; j < i; j++){
            bool mflag = false;
            if( seq[i][0] == seq[j][0]){
                
                for( int k = 2; k < 101; k++){
                    for( int l = 2; l < 101; l++){
                        
                        bool sflag = true;
                        
                        for( int m = 1; m < 4; m++){
                            
                            if( k * seq[i][m] != l * seq[j][m]){
                                sflag = false;
                                break;
                            }
                        }
                        if( sflag){
                            if( !f[i][k]){
                                ans++;
                                f[i][k] = true;
                            }
                            cout << i << " " << k << " " << j << " " << l << endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    int asdf = 99 * 99 - ans;
    cout << asdf << endl;
    return 0;
}
