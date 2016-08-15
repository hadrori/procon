#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, x, a[32];

void solve() {
    int sum = 0;
    rep(i,n) if(x>>i&1) sum += a[i];
    cout << sum << endl;
}

void input() {
    cin >> n >> x;
    rep(i,n) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
