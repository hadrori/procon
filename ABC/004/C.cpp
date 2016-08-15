#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n;

void solve() {
    string s = "123456";
    n %= 30;
    rep(i,n) swap(s[i%5],s[i%5+1]);
    cout << s << endl;
}

void input() {
    cin >> n;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
