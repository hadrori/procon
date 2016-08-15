#include <iostream>
#include <cmath>
#include <string>

#define ll long long int

using namespace std;

bool prime_judge( ll n);
void make_num( ll num, int k);
bool circle_judge( ll num);

int cnt;
int parts[4] = { 1, 3, 7, 9};


int main(){
    cnt = 13;
    for( int i = 3; i < 7; i++){
        make_num(0,i);
    }
    cout << cnt <<endl;
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
    for( int k = 0; k < 10; k++){
        ll a = rand() % ( n - 1 );
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

void make_num( ll num, int k){
    
    if( k == 0){
        if(circle_judge( num)){
            cnt++;
            cout << num << endl;
        }
        return;
    }
    for( int i = 0; i < 4; i++){
        ll tmp = num;
        tmp *= 10;
        tmp += parts[i];
        make_num( tmp, k-1);
    }
    
    return;
}

bool circle_judge( ll num){

    if( !prime_judge(num)){
        return false;
    }
    int k = 0;
    ll tmp = num;
    int sum = 0;
    while( tmp > 0){
        sum += tmp % 10;
        tmp /= 10;
        k++;
    }
    if(sum % 3 == 0){
        return false;
    }
    for( int i = 0; i < k - 1; i++){
        int t = num % 10;
        num /= 10;
        num += t * pow(10,(double)k-1);
        if( !prime_judge(num)){
            return false;
        }
    }
    
    return true;
}




