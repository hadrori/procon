#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

void solve() {
    const int N = 100;
    const int M = 300000;
    vector<vector<char>> vs(51, vector<char>(M,0));
    vs[0][0] = 1;
    repi(i,1,N+1) {
        for(int j = 50; j > 0; j--)
            rep(k,M-i*i) vs[j][k+i*i] = min(vs[j][k+i*i] + vs[j-1][k], 2);
    }
    i64 ans = 0;
    rep(i,M) if(vs[50][i] == 1) ans += i;
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
