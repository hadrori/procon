#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, m, a[128], b[128][128], c[128];

void solve() {
    rep(i,m) {
        rep(j,n) {
            c[j] += a[i] == b[i][j];
            if(j+1 != a[i]) c[a[i]-1] += a[i] != b[i][j];
        }
    }
    rep(i,n) cout << c[i] << endl;
}

void input() {
    cin >> n >> m;
    rep(i,m) cin >> a[i];
    rep(i,m) rep(j,n) cin >> b[i][j];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
