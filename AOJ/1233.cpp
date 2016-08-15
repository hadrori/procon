#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const string op = "+-*^";
const int mod = 1e9+7;

map<char,int> val;

inline bool canmul(char c) { return op.find(c) == string::npos; }

int expr(string &s, int l, int r) { return 0 };

void normalize(string &s) {
    string t = "";
    rep(i,s.size()) {
        if(s[i] == ' ') {
            int j = i;
            while(s[j] == ' ') j++;
            i = j-1;
        }
        else t.push_back(s[i]);
    }
    s = t;
    cerr << s << endl;
}

string s, t;

void solve() {
    srand(time(0));
    normalize(s);
    while(getline(cin,t), t != ".") {
        normalize(t);
        continue
        bool ok = 1;
        rep(_,100) {
            val.clear();
            rep(i,26) val[i+'a'] = rand()%mod;
            if(expr(s,0,s.size()) != expr(t,0,t.size())) { ok = 0; break; }
        }
        puts(ok? "yes", "no");
    }
}

bool input() {
    getline(cin,s);
    return s != ".";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) solve();
    return 0;
}
