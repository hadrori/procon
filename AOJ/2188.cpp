#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int pw[] = {-24,-21,-18,-15,-12,-9,-6,-3,-2,-1,1,2,3,6,9,12,15,18,21,24};
const vector<string> ut = {"yocto","zepto","ato","femto","pico","nano","micro","milli","centi","deci","deca","hecto","kilo","mega","giga","tera","peta","exa","zetta","yotta"};
string s, t, u;

void solve()
{
    int p = -1, q = -1, n = s.size();
    rep(i,n) if(s[i] != '.' and s[i] != '0') {
        q = i;
        break;
    }
    rep(i,n) if(s[i] == '.') {
        p = i;
        break;
    }
    if(p < 0) p = n;
    else {
        s = s.substr(0,p)+s.substr(p+1);
        if(q > p) q--;
    }
    p--;
    s = s.substr(q);
    int x = p-q, k = 0;
    if(t.size()) {
        rep(i,ut.size()) if(t == ut[i]) k = i;
        x += pw[k];
    }
    s = s.substr(0,1)+"."+s.substr(1);
    if(s[s.size()-1] == '.') s = s.substr(0,s.size()-1);
    cout << s << " * 10^" << x << " " << u << endl;
}

void input()
{
    string tmp;
    getline(cin, tmp);
    stringstream ss(tmp);
    vector<string> res;
    while(ss >> tmp) res.push_back(tmp);
    if((int)res.size() == 2) {
        s = res[0];
        t = "";
        u = res[1];
    }
    else {
        s = res[0];
        t = res[1];
        u = res[2];
    }
}

int main()
{
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        input();
        solve();
    }
    return 0;
}
