#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int inf = 1e9;
int n, m, w[310][310];

void solve() {
    rep(k,n) rep(i,n) rep(j,n) w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
    int ans = inf;
    rep(i,n) {
        int c = 0;
        rep(j,n) c = max(c, w[i][j]);
        ans = min(ans, c);
    }
    cout << ans << endl;
}

void input() {
    cin >> n >> m;
    rep(i,n) rep(j,n) w[i][j] = inf;
    rep(i,n) w[i][i] = 0;
    rep(i,m) {
        int a, b, t; cin >> a >> b >> t; a--; b--;
        w[a][b] = w[b][a] = t;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
