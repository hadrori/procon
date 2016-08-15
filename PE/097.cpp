#include <iostream>

#define ll long long int

using namespace std;

int main(){
    
    ll num = 28433;
    ll d = 10000000000;
    
    for( int i = 0; i < 7830457; i++){
        num *= 2;
        num %= d;
    }
    
    num++;
    
    cout << num << endl;
    
    return 0;
}