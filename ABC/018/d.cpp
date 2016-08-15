#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, m, p, q, r, x[512], y[512], z[512];

void solve() {
    int ans = 0;
    rep(s,1<<n) if(__builtin_popcount(s) <= p) {
        vector<int> vs(m);
        rep(i,r) if(s>>x[i]&1) vs[y[i]] -= z[i];
        sort(begin(vs),end(vs));
        ans = max(ans, -accumulate(begin(vs), begin(vs)+q, 0));
    }
    cout << ans << endl;
}

void input() {
    cin >> n >> m >> p >> q >> r;
    rep(i,r) {
        cin >> x[i] >> y[i] >> z[i];
        x[i]--; y[i]--;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
