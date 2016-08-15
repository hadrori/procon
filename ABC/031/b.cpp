#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int l, h, n, x[64];

void solve() {
    rep(i,n) {
        int ans = 0;
        if(x[i] < l) ans = l-x[i];
        else if(x[i] > h) ans = -1;
        cout << ans << endl;
    }
}

void input() {
    cin >> l >> h >> n;
    rep(i,n) cin >> x[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
