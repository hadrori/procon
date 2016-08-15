#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, a[1024];
string s[1024];

string solve() {
    int m = accumulate(a,a+n,0)/2;
    rep(i,n) if(a[i] > m) return s[i];
    return "atcoder";
}

void input() {
    cin >> n;
    rep(i,n) cin >> s[i] >> a[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
