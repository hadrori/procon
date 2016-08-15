#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int n, m, ps[1024];
map<string,int> id;
vector<int> cs[1024];

bool qc(int c, int p) { return ps[c] == p; }
bool qa(int a, int d) {
    while(~ps[d]) {
        d = ps[d];
        if(d == a) return 1;
    }
    return 0;
}
bool qs(int x, int y) { return x != y and ps[x] == ps[y]; }

void solve() {
    rep(i,m) {
        string a, b, q, _;
        cin >> a >> _ >> _ >> q >> _ >> b;
        int x = id[a], y = id[b.substr(0,b.size()-1)], ans = 0;
        if(q == "child" and qc(x,y)) ans = 1;
        else if(q == "ancestor" and qa(x,y)) ans = 1;
        else if(q == "sibling" and qs(x,y)) ans = 1;
        else if(q == "parent" and qc(y,x)) ans = 1;
        else if(q == "descendant" and qa(y,x)) ans = 1;
        puts(ans? "True": "False");
    }
}

bool input() {
    cin >> n >> m;
    if(!n and !m) return 0;
    id.clear();
    string s; cin.ignore();
    int p[1024];

    rep(i,n) {
        cs[i].clear();
        getline(cin, s);
        int dep = 0;
        for(; s[dep] == ' '; dep++);
        id[s.substr(dep)] = i;
        p[dep] = i;
        if(!dep) {
            ps[i] = -1;
            continue;
        }
        ps[i] = p[dep-1];
        cs[p[dep-1]].push_back(i);
    }
    return 1;
}

int main() {
    while(input()) {
        solve();
        puts("");
    }
    return 0;
}
