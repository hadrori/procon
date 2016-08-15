#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll pi = 166, hi = 144;
    ll p = pi*(3*pi-1)/2, h = hi*(2*hi-1);
    while(1){
	if(p > h){
	    hi++;
	    h = hi*(2*hi-1);
	}else if(p < h){
	    pi++;
	    p = pi*(3*pi-1)/2;
	}else{
	    cout << p << endl;
	    break;
	}
    }
}
