#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

i64 a, b, c, d, e, n, h;

void solve() {
    i64 ans = LLONG_MAX;
    rep(i,n+1) {
        i64 res = (n-i)*e-h-i*b, j = res < 0? 0: res/(d+e)+1;
        ans = min(ans, i*a+j*c);
    }
    cout << ans << endl;
}

void input() {
    cin >> n >> h >> a >> b >> c >> d >> e;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
