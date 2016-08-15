#include <iostream>

#define ll long long int

using namespace std;

int dollers( int coin, int sum, int cnt){
    
    for( int i = 0; i <= 200; i++){
        if( sum + coin * i > 200 ){
            break;
        }else if( sum + coin * i == 200){
            cnt++;
            break;
        }else if( sum + coin * i < 200){
            int ncoin = coin / 2;
            if( ncoin == 25){
                ncoin = 20;
            }
            if( ncoin > 0){
                cnt = dollers( ncoin, sum + coin * i, cnt);
            }
        }
    }
    
    return cnt;
}

int main(){
    
    ll cnt = 0;
    
    cnt = dollers( 200, 0, 0);
    
    cout << cnt << endl;
    
    return 0;
}