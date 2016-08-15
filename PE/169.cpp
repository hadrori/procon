#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const string NS = "100001000101100101010001011000010100000000010100100001001010000000000000000000000000";
const int M = 100;
const bitset<M> N(NS);
i64 dp[M][M];

void solve() {
    dp[M-1][M-1] = 1;
    for(int i = M-2; i >= 0; i--) {
        if(!N.test(i)) {
            rep(j,M) dp[i][j] = dp[i+1][j];
            continue;
        }
        rep(j,M) {
            if(j != i) dp[i][j] += dp[i+1][j];
            if(j > i) {
                for(int k = i-1; k >= 0; k--)
                    dp[i][k] += dp[i+1][j];
            }
        }
    }
    cout << accumulate(dp[0], dp[0]+M, 0LL) << endl;
}

void input() {
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
