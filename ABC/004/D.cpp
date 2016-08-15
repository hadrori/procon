#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int inf = 1e9;

int r, g, b;

inline int sum(int k) { return k*(k+1)/2; }

int simu(int gl, int gr) {
    int ret = 0;
    if(gl <= 0 and gr >= 0) ret = sum(abs(gl)) + sum(gr-1);
    else if(gl > 0) ret = sum(gr-1) - sum(gl-1);
    else ret = sum(abs(gl)) - sum(abs(gr));
    int rl = min(-100,gl), rr = rl;
    int bl = max(100, gr), br = bl;
    rep(i,r) {
        int rc = rr == gl ? inf : rr+100, lc = -99-rl;
        if(lc > rc) rr++;
        else rl--;
        ret += min(lc,rc);
    }
    rep(i,b) {
        int rc = br-100, lc = gr == bl ? inf : 101-bl;
        if(lc > rc) br++;
        else bl--;
        ret += min(lc,rc);
    }
    return ret;
}

void solve() {
    int ans = 1e9;
    repi(gl,-300, 300) {
        int gr = gl + g;
        ans = min(ans, simu(gl,gr));
    }
    cout << ans << endl;
}

void input() {
    cin >> r >> g >> b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
