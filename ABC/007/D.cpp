#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

i64 A, B, dp[32][2][2];

i64 calc(i64 up) {
    const string s = to_string(up);
    const int n = s.size();
    memset(dp,0,sizeof(dp));
    dp[0][1][0] = 1;
    rep(i,n) rep(j,2) rep(k,2) if(dp[i][j][k]) rep(v,10) {
        if(j and v > s[i]-'0') continue;
        const int ni = i+1, nj = j and v == s[i]-'0', nk = k or v%5 == 4;
        dp[ni][nj][nk] += dp[i][j][k];
    }
    return dp[n][0][1] + dp[n][1][1];
}

void solve() {
    cout << calc(B) - calc(A-1) << endl;
}

void input() {
    cin >> A >> B;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
