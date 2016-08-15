#include <iostream>

#define ll long long int

using namespace std;


int main(){
    
    int cnt = 0;

    for( int n = 100; n > 0; n--){
        ll temp = 1;
        bool cflag = false;
        for( int r = 1; r <= n; r++){
            temp = temp * ( n - r + 1) / r;
            if( temp > 1000000){
                cflag = true;
                cnt += n - 2 * r + 1;
                break;
            }
        }
        if( !cflag){
            break;
        }
    }
    
    cout << cnt << endl;
    return 0;
}



/*

 nCr = nCr-1 * ( n - r + 1)/r

*/