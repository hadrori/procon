#include <iostream>

using namespace std;

int eulerPhi(int n){
    if(n == 0) return 0;
    int ret = n;
    for(int x = 2; x*x <= n; x++){
	if(n % x == 0){
	    ret -= ret / x;
	    while(n % x == 0) n /= x;
	}
    }
    if(n > 1) ret -= ret / n;
    return ret;
}

int main(){
    double maxp = 0;
    int ans = 0;
    for(int n = 2; n < 1000001; n++){
	int p = eulerPhi(n);
	if(maxp < 1.0*n/p){
	    maxp = 1.0 * n / p;
	    ans = n;
	}
//	cerr << n << ' ' << p << endl;
    }
    cout << ans << endl;
}
