#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
inline void chmax(int &x, int y) { x = max(x,y); }

int w, n, m, a[64], b[64], dp[10010][60];

void solve() {
    rep(i,n) for(int j = w; j >= a[i]; j--)
        rep(k,m) chmax(dp[j][k+1],dp[j-a[i]][k]+b[i]);
    cout << dp[w][m] << endl;
}

void input() {
    cin >> w >> n >> m;
    rep(i,n) cin >> a[i] >> b[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
