#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int wf[32][32], n, m;
string qs[64], rs[64];

bool check(string a, string b) {
    if(a.size() != b.size()) return false;
    rep(i,a.size()) {
        int x = a[i]-'a', y = b[i]-'a';
        if(!wf[x][y]) return false;
    }
    return true;
}

void solve() {
    rep(k,32) rep(i,32) rep(j,32) wf[i][j] |= wf[i][k] & wf[k][j];
    rep(i,m) {
        if(check(qs[i], rs[i])) puts("yes");
        else puts("no");
    }
}

void input() {
    rep(i,32) rep(j,32) wf[i][j] = 0;
    rep(i,32) wf[i][i] = 1;
    cin >> n >> m;
    rep(i,n) {
        char a, b; cin >> a >> b;
        wf[a-'a'][b-'a'] = 1;
    }
    rep(i,m) cin >> qs[i] >> rs[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
