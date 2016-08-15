#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, t, a[100010];

void solve() {
    int ans = 0;
    a[n] = 20000000;
    rep(i,n) ans += min(t,a[i+1]-a[i]);
    cout << ans << endl;
}

void input() {
    cin >> n >> t;
    rep(i,n) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
