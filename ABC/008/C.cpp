#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, c[128];

void solve() {
    double ans = 0;
    rep(i,n) {
        int pc = 0;
        rep(j,n) pc += i != j and c[i]%c[j] == 0;
        ans += (pc+2)/2/(pc+1.);
    }
    cout << fixed << setprecision(12) << ans << endl;
}

void input() {
    cin >> n;
    rep(i,n) cin >> c[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
