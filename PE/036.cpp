#include <iostream>
#include <bitset>

#define ll long long int

using namespace std;

bool dpalinJ( ll num);
bool bpalinJ( bitset<20> num);

int main(){
    
    ll ans = 0;
    
    for( int i = 1; i <= 1000000; i++){
        if( dpalinJ(i)){
            bitset<20> bs(i);
            if( bpalinJ(bs)){
                ans += i;
            }
        }
    }
    
    
    cout << ans << endl;
    return 0;
}

bool dpalinJ( ll num){
    
    int dig[10] = {0};
    ll tmp = num;
    int cnt = 0;
    
    while( tmp > 0){
        dig[cnt++] = tmp % 10;
        tmp /= 10;
    }
    for( int i = 0; i < cnt / 2; i++){
        if( dig[i] != dig[cnt-1-i]){
            return false;
        }
    }
    
    return true;
}

bool bpalinJ( bitset<20> num){
    
    if( num[0] == 0){
        return 0;
    }
    
    bool dig[20] = {0};
    int max = 0;
    for( int i = 0; i < 20; i++){
        dig[i] = num[i];
        if( num[i]){
            max = i;
        }
    }
    for( int i = 0; i < (max+1)/2; i++){
        if( dig[i] != dig[max-i]){
            return false;
        }
    }
    
    return true;
}