#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const string cs[] = {"ld","mb","mp","nc","nd","ng","nt","nw","ps","qu","cw","ts"};
int n, cnt[40][40];
vector<vector<int>> vs;

void solve()
{
    for(auto &s: vs) {
        rep(i,s.size()-1) {
            if(s[i] < 0 or s[i+1] < 0) continue;
            cnt[s[i]][s[i+1]]++;
        }
    }
    rep(i,38) {
        string s, t;
        int ans = -1;
        if(i < 26) s = string(1,i+'a');
        else s = cs[i-26];
        rep(j,38) if(ans < cnt[i][j]) {
            ans = cnt[i][j];
            if(j < 26) t = string(1,j+'a');
            else t = cs[j-26];
        }
        cout << s << ' ' << t << ' ' << ans << endl;
    }
}

void parse(string &s)
{
    vs.push_back(vector<int>());
    rep(i,s.size()) {
        if(s[i] == ' ') {
            vs.back().push_back(-1);
            continue;
        }
        if(i < (int)s.size()-1) {
            const string t = string(1,s[i])+string(1,s[i+1]);
            int k = -1;
            rep(j,12) if(cs[j] == t) k = j+26;
            if(~k) {
                vs.back().push_back(k);
                i++;
                continue;
            }
        }
        vs.back().push_back(s[i]-'a');
    }
}

void input()
{
    cin >> n;
    cin.ignore();
    string s;
    rep(i,n) {
        getline(cin,s);
        parse(s);
    }
}

int main()
{
    input();
    solve();
    return 0;
}
