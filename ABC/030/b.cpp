#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int h, m;

void solve() {
    h %= 12;
    double hr = 30*h+m*0.5, mr = 6*m, d = abs(hr-mr);
    cout << min(d,360-d) << endl;
}

void input() {
    cin >> h >> m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
