#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, m;
string s, t;

void solve() {
    vector<int> sc(26,0), tc;
    rep(i,n) sc[s[i]-'a']++;
    t = s;
    rep(i,n) {
        rep(j,26) if(sc[j]) {
            const char c = 'a'+j;
            t[i] = c;
            tc = sc; tc[j]--;
            int d = 0;
            rep(k,i+1) d += s[k] != t[k];
            repi(k,i+1,n) {
                if(tc[s[k]-'a']) tc[s[k]-'a']--;
                else d++;
            }
            if(d <= m) {
                sc[j]--;
                break;
            }
        }
    }
    cout << t << endl;
}

void input() {
    cin >> n >> m >> s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
