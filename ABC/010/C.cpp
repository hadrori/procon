#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

double T, V, x[1024], y[1024];
int n;

double d(int i, int j) { return hypot(x[i]-x[j],y[i]-y[j]); }

bool solve() {
    rep(i,n) if(d(i+2,0)+d(i+2,1) < T*V+1e-9) return 1;
    return 0;
}

void input() {
    rep(i,2) cin >> x[i] >> y[i];
    cin >> T >> V >> n;
    rep(i,n) cin >> x[2+i] >> y[2+i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << (solve()? "YES": "NO") << endl;
    return 0;
}
