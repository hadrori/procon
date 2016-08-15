#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, a[100010];
set<int> s;

void solve() {
    rep(i,n) {
        while(a[i]%2 == 0) a[i] /= 2;
        s.insert(a[i]);
    }
    cout << s.size() << endl;
}

void input() {
    cin >> n;
    rep(i,n) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
