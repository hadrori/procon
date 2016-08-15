#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int mod = 1e9+7;
inline void add(int &x, int y) { x=(x+y)%mod; }
inline int mul(int x, int y) { return 1LL*x*y%mod; }
int n, m, up[256], dp[256][256];

int solve() {
    dp[0][0] = 1;
    rep(i,m) rep(j,i+1) {
        if(up[i]) {
            add(dp[i+1][j], mul(dp[i][j], j));
            add(dp[i+1][j+1], dp[i][j]);
        }
        else {
            add(dp[i+1][j], mul(dp[i][j],j));
            if(j) add(dp[i+1][j-1], mul(dp[i][j], j*j));
        }
    }
    return dp[m][0];
}

void input() {
    cin >> n; m = 0;
    char c;
    rep(i,n) {
        cin >> c;
        if(c == 'U') up[m++] = 1;
        else if(c == 'D') up[m++] = 0;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
