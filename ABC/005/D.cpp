#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, d[64][64], q, p[4096];

int query(int m) {
    int ans = 0;
    repi(w,1,n+1) {
        int h = m/w;
        rep(i,n-h+1) rep(j,n-w+1)
            ans = max(ans, d[i+h][j+w]-d[i+h][j]-d[i][j+w]+d[i][j]);
    }
    repi(h,1,n+1) {
        int w = m/h;
        rep(i,n-h+1) rep(j,n-w+1)
            ans = max(ans, d[i+h][j+w]-d[i+h][j]-d[i][j+w]+d[i][j]);
    }
    return ans;
}

void solve() {
    rep(i,n) rep(j,n) d[i+1][j+2] += d[i+1][j+1];
    rep(i,n) rep(j,n) d[i+2][j+1] += d[i+1][j+1];
    rep(i,q) cout << query(p[i]) << endl;
}

void input() {
    cin >> n;
    rep(i,n) rep(j,n) cin >> d[i+1][j+1];
    cin >> q;
    rep(i,q) cin >> p[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
