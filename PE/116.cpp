#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int N = 50;

i64 calc(int x) {
    i64 dp[N+10]; memset(dp,0,sizeof(dp));
    dp[0] = 1;
    rep(i,N) {
        dp[i+1] += dp[i];
        dp[i+x] += dp[i];
    }
    return dp[N]-1;
}

void solve() {
    cout << calc(2) + calc(3) + calc(4) << endl;
}

int main() {
    solve();
    return 0;
}
