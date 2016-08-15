#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, f[128], a[128], t[128], x[128], y[128];

inline double sq(double x) { return x*x; }
inline double dist(int i, int j) { return sqrt(sq(x[i]-x[j])+sq(y[i]-y[j])); }

void solve() {
    pair<double,int> ans[2] = {make_pair(-1,-1), make_pair(-1,-1)};
    repi(i,1,n) {
        if(t[i] != t[i-1] or a[i] == a[i-1]) continue;
        ans[t[i]] = max(ans[t[i]], make_pair(dist(i-1,i), f[i-1]-f[i]));
    }
    rep(i,2) {
        if(ans[i].first < 0) cout << "-1 -1" << endl;
        else cout << ans[i].first << ' ' << -ans[i].second/60.0 << endl;
    }
}

void input() {
    cin >> n;
    rep(i,n) cin >> f[i] >> a[i] >> t[i] >> x[i] >> y[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
