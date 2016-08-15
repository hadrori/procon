#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const string a = "atcoder";
string s, t;

bool solve() {
    rep(i,s.size()) if (s[i] != t[i]) {
        if(s[i] != '@' and (t[i] != '@' or a.find(s[i]) == string::npos)) return 0;
        if(t[i] != '@' and (s[i] != '@' or a.find(t[i]) == string::npos)) return 0;
    }
    return 1;
}

void input() {
    cin >> s >> t;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << (solve()? "You can win" : "You will lose") << endl;
    return 0;
}
