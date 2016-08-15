#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int n;
string s, t;

inline bool cmp(const string &a, const string &b) { return a.size() < b.size(); }

bool pal(int l, int r) {
    rep(i,r-l) if(s[l+i] != s[r-i-1]) return 0;
    return 1;
}

void solve() {
    s = "";
    for(auto &c: t) if(isalpha(c)) s.push_back(toupper(c));
    vector<string> res;
    set<string> ans;
    set<string> ign;
    n = s.size();
    rep(i,2*n-1) {
        int l, r, m = i/2;
        if(i%2) l = m-1, r = m+2;
        else l = m-2, r = m+2;
        vector<string> cand;
        while(l >= 0 and r <= n) {
            if(pal(l,r)) cand.push_back(s.substr(l,r-l));
            r++;
            l--;
        }
        sort(begin(cand),end(cand),cmp);
        if(cand.size()) ans.insert(cand.back());
        rep(i,cand.size()-1) ign.insert(cand[i]);
    }
    for(auto &e: ans) if(!ign.count(e)) res.push_back(e);
    sort(begin(res),end(res));
    rep(i,res.size()) cout << res[i] << (i==(int)res.size()-1? "": " ");
    cout << endl;
}

bool input() {
    return getline(cin, t);
}

int main() {
    while(input()) solve();
    return 0;
}
