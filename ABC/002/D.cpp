#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, m, f[16][16];

void solve() {
    int ans = 0;
    rep(s,1<<n) {
        int c = 1;
        rep(i,n) if(s>>i&1) repi(j,i+1,n) if(s>>j&1) c &= f[i][j];
        ans = max(ans, c*__builtin_popcount(s));
    }
    cout << ans << endl;
}

void input() {
    cin >> n >> m;
    rep(i,m) {
        int x, y; cin >> x >> y;
        x--; y--;
        f[x][y] = f[y][x] = 1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
