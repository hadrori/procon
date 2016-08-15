#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

string s;

void solve() {
    s.push_back('~');
    string t;
    char pv = '~';
    int c = 0;
    rep(i,s.size()) {
        if(s[i] == pv) c++;
        else {
            if(c) t += string(1,pv)+to_string(c);
            c = 1;
            pv = s[i];
        }
    }
    cout << t << endl;
}

void input() {
    cin >> s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
