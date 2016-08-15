#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

string s;
int k;

void solve() {
    set<string> t;
    rep(i,s.size()-k+1) t.insert(s.substr(i,k));
    cout << t.size() << endl;
}

void input() {
    cin >> s >> k;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
