#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int N = 15;

long double dp[N+1][N+1];

void solve() {
    dp[0][0] = 1;
    rep(i,N) rep(j,i+1) {
        dp[i+1][j] += dp[i][j] * (i+1) / (i+2);
        dp[i+1][j+1] += dp[i][j] / (i+2);
    }
    long double sum = 0;
    repi(j,N/2+1,N+1) sum += dp[N][j];
    cerr << sum << endl;
    cout << int(1.0/sum) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    solve();
    return 0;
}
