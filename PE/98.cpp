#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

inline i64 sq(i64 x) { return x*x; }

bool is_sq(i64 x) {
    i64 y = sqrt(x);
    return sq(y) == x or sq(y-1) == x or sq(y+1) == x;
}

map<string, vector<string> > dict;

vector<vector<string>> sqs;
int max_len;

void gen_sq() {
    sqs.resize(max_len+1);
    for(i64 x = 1; ; x++) {
        i64 y = x*x;
        string s = to_string(y);
        if((int)s.size() > max_len) break;
        sqs[s.size()].push_back(s);
    }
}

i64 to_i(string s) {
    i64 ret = 0;
    rep(i,s.size()) ret = 10 * ret + s[i];
    return ret;
}

void solve() {
    gen_sq();
    i64 ans = 0;
    for (auto &d: dict) {
        string s = d.first;
        vector<string> &ss = d.second;
        s.erase(unique(begin(s),end(s)),end(s));
        if(s.size() > 10) continue;
        for(auto it = begin(ss); it != end(ss); it++) {
            string u = *it;
            for (auto &ns: sqs[u.size()]) {
                char conv[256]; memset(conv,'~',sizeof(conv));
                bool ok = 1;
                rep(i,ns.size()) {
                    if(conv[(int)u[i]] != '~' and ns[i] != conv[(int)u[i]]) {
                        ok = 0;
                        break;
                    }
                    conv[(int)u[i]] = ns[i];
                }
                if(!ok) continue;

                for(auto jt = it+1; jt != end(ss); jt++) {
                    string v = *jt;
                    rep(i,v.size()) v[i] = conv[(int)v[i]];
                    if(is_sq(to_i(v))) ans = max({ans, to_i(v), to_i(ns)});
                }
            }
        }
    }
    cout << ans << endl;
}

void input() {
    string s;
    while(cin >> s) {
        string t = s; sort(begin(t),end(t));
        max_len = max(max_len, (int)t.size());
        dict[t].push_back(s);
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
