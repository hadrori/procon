#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

string s;
int cnt[256];

void solve() {
    rep(i,s.size()) cnt[s[i]]++;
    repi(i,'A','G') cout << cnt[i] << (i=='F'? '\n': ' ');
}

void input() {
    cin >> s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
