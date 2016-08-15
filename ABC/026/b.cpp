#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, r[1024];

void solve() {
    int ans = 0, sig = 1;
    sort(r,r+n);
    reverse(r,r+n);
    rep(i,n) {
        ans += r[i]*r[i]*sig;
        sig *= -1;
    }
    cout << ans*M_PI << endl;
}

void input() {
    cin >> n;
    rep(i,n) cin >> r[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
