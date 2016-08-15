#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int N = 50;
i64 dp[N+10];

void solve() {
    dp[0] = 1;
    rep(i,N) rep(j,4) dp[i+j+1] += dp[i];
    cout << dp[N] << endl;
}

int main() {
    solve();
    return 0;
}
