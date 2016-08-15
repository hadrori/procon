#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

char f[4][4];

void solve() {
    rep(i,4) rep(j,4) cout << f[3-i][3-j] << (j==3? '\n': ' ');
}

void input() {
    rep(i,4) rep(j,4) cin >> f[i][j];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
