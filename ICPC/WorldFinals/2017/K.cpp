#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

struct StringHash {
    const vector<i64> ms = { 999999937LL, 1000000007LL, 1000000009LL };
    const i64 base = 9973;
    int n;
    vector<vector<i64>> hs, pw;
    StringHash() {}
    StringHash(const string &s) {
        hs.assign(ms.size(), vector<i64>());
        pw.assign(ms.size(), vector<i64>());
        n = s.size();
        for (int i = 0; i < (int)ms.size(); i++) {
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for (int j = 0; j < n; j++) {
                pw[i][j+1] = pw[i][j]*base%ms[i];
                hs[i][j+1] = (hs[i][j]*base+s[j])%ms[i];
            }
        }
    }

    i64 hash(int l, int r, int i) { return ((hs[i][r]-hs[i][l]*pw[i][r-l])%ms[i]+ms[i])%ms[i]; }

    bool match(int l1, int r1, int l2, int r2) {
        bool ret = 1;
        for (int i = 0; i < (int)ms.size(); i++) ret &= hash(l1,r1,i)==hash(l2,r2,i);
        return ret;
    }

    bool match(int l, int r, i64 h[]) {
        bool ret = 1;
        for (int i = 0; i < (int)ms.size(); i++) ret &= hash(l,r,i)==h[i];
        return ret;
    }
};

int n, m;
vector<string> ss;
vector<pair<vector<int>, int>> seq;

pair<vector<int>, int> calc(int id) {
    const string s = ss[id];
    vector<int> ret;
    StringHash sh(s);
    rep(i,s.size()) if(sh.match(0,i,s.size()-i,s.size()) && (n > 2*s.size()-2 || i >= 2*s.size()-n)) ret.push_back(i);
    reverse(begin(ret), end(ret));
    return make_pair(ret, id);
}

void solve() {
    rep(i,m) seq.push_back(calc(i));
    sort(begin(seq),end(seq));
    rep(i,m) cout << ss[seq[i].second] << endl;
}

void input() {
    cin >> n >> m;
    rep(i,m) {
        string s;
        cin >> s;
        ss.push_back(s);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
