#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, f[4];

int solve() {
    int sum = accumulate(f, f+n, 0), ans = sum;
    rep(s,1<<n) {
        int v = 0;
        rep(i,n) if(s>>i&1) v += f[i];
        ans = min(ans, max(v, sum-v));
    }
    return ans;
}

void input() {
    cin >> n;
    rep(i,n) cin >> f[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
