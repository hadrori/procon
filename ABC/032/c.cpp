#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, k, s[100010];

int solve() {
    rep(i,n) if(!s[i]) return n;
    i64 pd = 1;
    int l = 0, r = 0, ans = 0;
    while(r < n) {
        pd *= s[r++];
        while(l < r and pd > k) pd /= s[l++];
        ans = max(ans, r-l);
    }
    return ans;
}

void input() {
    cin >> n >> k;
    rep(i,n) cin >> s[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
