#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, a, b, d;

void solve() {
    int x = 0;
    while(n--) {
        string s;
        cin >> s >> d;
        d = max(a,min(b,d));
        if(s == "East") x += d;
        else x -= d;
    }
    if(x < 0) cout << "West ";
    if(x > 0) cout << "East ";
    cout << abs(x) << endl;
}

void input() {
    cin >> n >> a >> b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
