#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

vector<string> ss;
int r, c, w, sp;

void solve() {
    int ps = (ss.size()+r*c-1)/(r*c);
    ss.resize(ps*r*c, "");
    for(auto &s: ss) s.resize(w,'.');
    string pc(sp,'.');
    rep(p,ps) {
        rep(i,r) rep(j,c) cout << ss[p*r*c+i+j*r] << (j==c-1? "\n": pc);
        cout << "#" << endl;
    }
    cout << "?" << endl;
}

bool input() {
    ss.clear();
    cin >> r;
    if(!r) return 0;
    cin >> c >> w >> sp;
    string s;
    cin.ignore();
    while(getline(cin, s), s != "?") {
        if(!s.size()) ss.push_back(s);
        while(s.size() > w) {
            ss.push_back(s.substr(0,w));
            s = s.substr(w);
        }
        if(s.size()) ss.push_back(s);
    }
    return 1;
}

int main() {
    while(input()) solve();
    return 0;
}
