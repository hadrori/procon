#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int h, w, m, n, x[100010], y[100010], cx[100010], cy[100010], scx[100010];

void solve() {
    rep(i,n) {
        cx[x[i]]++;
        cy[y[i]]++;
    }
    memcpy(scx,cx,sizeof(cx));
    sort(scx,scx+w);

    i64 ans = 0;
    rep(i,h) {
        int res = m-cy[i];
        ans += upper_bound(scx,scx+w,res)-lower_bound(scx,scx+w,res);
    }
    rep(i,n) {
        if(cx[x[i]] + cy[y[i]] == m) ans--;
        if(cx[x[i]] + cy[y[i]] == m+1) ans++;
    }
    cout << ans << endl;
}

void input() {
    cin >> h >> w >> m >> n;
    rep(i,n) {
        cin >> y[i] >> x[i];
        x[i]--; y[i]--;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
