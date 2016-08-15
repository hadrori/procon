#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main(){
    ll ans = 1, num = 1, cnt = 1, dig = 1;
    while(true){
	num++;	
	cnt += (int)log10(num)+1;
	if(dig < (int)log10(cnt)+1){
	    ll diff = cnt-pow(10.0,(double)(int)log10(cnt));
	    ll tmp = num;
	    tmp /= pow(10,(double)diff);
	    ans *= tmp % 10;
	    cerr << "num: " << num << " cnt: " << cnt << " diff: " << diff << " d: " << tmp % 10 << endl;
	}
	dig = (int)log10(cnt)+1;
	if(num > 1000000) break;
    }
    cout << ans << endl;
}
