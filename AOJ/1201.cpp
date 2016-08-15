#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int vs[16], rvs[16], used[16], cs[16];

int to_i(string s) {
    int ret = 0;
    for(auto &c: s) ret = ret*2+c-'0';
    return ret;
}

int rev(int v) {
    int ret = 0;
    rep(i,5) ret += (v>>i&1)<<(4-i);
    return ret;
}

bool can(int p, int v) {
    rep(i,5) if((cs[i]>>p&1)+(v>>i&1) != 1) return 0;
    return 1;
}

int dfs2(int p) {
    if(p == 5) return 1;
    int ret = 0;
    rep(i,10) if(!used[i] and (can(p,vs[i]) or can(p, rvs[i]))) {
        used[i] = 1;
        ret += dfs2(p+1);
        used[i] = 0;
    }
    return ret;
}

int dfs(int p) {
    if(p == 5) return dfs2(0);
    int ret = 0;
    rep(i,10) if(!used[i]) {
        used[i] = 1;
        cs[p] = vs[i];
        ret += dfs(p+1);
        if(vs[i] != rvs[i]) {
            cs[p] = rvs[i];
            ret += dfs(p+1);
        }
        used[i] = 0;
    }
    return ret;
}

int solve() {
    memset(used,0,sizeof(used));
    rep(i,10) rvs[i] = rev(vs[i]);
    return dfs(0)/8;
}

bool input() {
    string s;
    cin >> s;
    if(s == "END") return 0;
    vs[0] = to_i(s);
    rep(i,9) {
        cin >> s;
        vs[i+1] = to_i(s);
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) {
        cout << solve() << endl;
    }
    return 0;
}
