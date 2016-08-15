#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define ll long long int

using namespace std;


bool prime_judge( ll n);

void make_num( bool* nflag, int* nums, int i, int dig);

ll mrand(){
    srand((ll)time(NULL));
    return rand();
}


int main(){
    
    int nums[8] = {0};
    bool nflag[8] = {false};
    nflag[0] = true;
    for( int k = 7; k > 0; k--){
        make_num( nflag, nums, k-1, k);
    }

    return 0;
}

void make_num( bool* nflag, int* nums, int i, int dig){
    
    for( nums[i] = dig; nums[i] > 0; nums[i]--){
        if( !nflag[nums[i]]){
            nflag[nums[i]] = true;
            if( i > 0){
                make_num( nflag, nums, i-1, dig);
            }else{
                ll n = 0;
                for( int j = 0; j < dig; j++){
                    n += nums[j] * pow( 10, (double)j);
                }
                if( prime_judge(n)){
                    cout << n << endl;
                    exit(1);
                }
            }
            nflag[nums[i]] = false;
        }
        
    }
    
    return;
}

//ミラーラビン素数判定法
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
