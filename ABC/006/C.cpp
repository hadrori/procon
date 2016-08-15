#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, m;

void solve() {
    rep(z,n+1) {
        int k = m-4*z, p = n-z;
        int x = 3*p-k, y = k-2*p;
        if(x < 0 or y < 0) continue;
        cout << x << ' ' << y << ' ' << z << endl;
        return;
    }
    cout << "-1 -1 -1" << endl;
}

void input() {
    cin >> n >> m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
