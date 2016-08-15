#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, m, f[10][10];

void solve() {
    rep(i,n) {
        vector<int> g(n);
        rep(j,n) if(j != i and f[i][j]) {
            rep(k,n) if(k != i and k != j and f[j][k] and !f[i][k]) {
                g[k] = 1;
            }
        }
        cout << accumulate(begin(g),end(g),0) << endl;
    }
}

void input() {
    cin >> n >> m;
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        f[a][b] = f[b][a] = 1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
