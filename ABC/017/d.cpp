#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int mod = 1e9+7;
inline int add(int x, int y) { return (x+y)%mod; }
inline int sub(int x, int y) { return (x-y+mod)%mod; }
int n, m, f[100010], dp[100010], last[100010], sum[100010];

void solve() {
    int pv = 0;
    dp[0] = sum[1] = 1;
    rep(i,n) {
        pv = max(pv, last[f[i]]);
        dp[i+1] = sub(sum[i+1], sum[pv]);
        sum[i+2] = add(sum[i+1], dp[i+1]);
        last[f[i]] = i+1;
    }
    cout << dp[n] << endl;
}

void input() {
    cin >> n >> m;
    rep(i,n) cin >> f[i];
    rep(i,n) f[i]--;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
