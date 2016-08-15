#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <stack>
#include <complex>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
const long long mod = 1000000007;

ll r, c, x, y, d, l;
ll comb[1000][1000];

ll cmb(int n,int k){
    if(n<k || n<=0) return 0;
    if(n==k or k==0) return comb[n][k]=1;
    if(comb[n][k]!=0) return comb[n][k];
    return comb[n][k] = (cmb(n-1,k-1)+cmb(n-1,k))%mod;
}

inline void sub(ll &x, ll y) { x = x-y; }
inline ll f(ll h, ll w, ll dl) { if(h < 0 or w < 0) return 0; return cmb(h*w,dl); }

int main(){
    cin >> r >> c >> x >> y >> d >> l;
    ll pos=(r-x+1)*(c-y+1);
    ll dl = d+l;
    ll ans = 0;
    ans = f(x,y,dl);
    sub(ans, f(x,y-1,dl)*2%mod);
    sub(ans, f(x-1,y,dl)*2%mod);
    ans = (ans + f(x,y-2,dl) + f(x-2,y,dl) + f(x-1,y-1,dl)*4)%mod;
    sub(ans, f(x-1,y-2,dl)*2%mod);
    sub(ans, f(x-2,y-1,dl)*2%mod);
    ans = (ans + f(x-2,y-2,dl))%mod;

    ans = ans * pos % mod;
    ans = ans * cmb(dl,d) %mod;
    cout << ans << endl;
    return 0;
}
