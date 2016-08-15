#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, a[100010], b[100010];

void solve() {
    int ans = 0;
    rep(i,n) {
        ans += b[a[i]];
        b[a[i]] = 1;
    }
    cout << ans << endl;
}

void input() {
    cin >> n;
    rep(i,n) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
