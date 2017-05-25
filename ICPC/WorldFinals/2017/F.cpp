#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const i64 inf = 1e18;
const double eps = 1e-9;
i64 D, K, r[300], p[300], cst[300][300], dp[300][300];

inline i64 sq(i64 x) { return x*x; }

i64 solve() {
    rep(i,D) repi(j,i+1,D+1) {
        i64 sum = 0, cnt = 0;
        repi(k,i,j) {
            sum += p[k] * r[k];
            cnt += p[k];
        }
        i64 av = round(1.0 * sum / cnt) + eps;
        repi(k,i,j) cst[i][j] += sq(av - r[k]) * p[k];
    }
    rep(i,D+1) rep(j,K+1) dp[i][j] = inf;
    dp[0][0] = 0;
    rep(i,D) rep(k,K) if(dp[i][k] < inf)
        repi(j,i+1,D+1) dp[j][k+1] = min(dp[j][k+1], dp[i][k]+cst[i][j]);
    return dp[D][K];
}

void input() {
    cin >> D >> K;
    rep(i,D) cin >> r[i] >> p[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
