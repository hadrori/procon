#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int a[4];

void solve() {
    rep(i,3) {
        int c = 0;
        rep(j,3) if(a[j] >= a[i]) c++;
        cout << c << endl;
    }
}

void input() {
    rep(i,3) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
