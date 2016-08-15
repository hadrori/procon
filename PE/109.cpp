#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
vector<pair<int,int>> vs;

int dfs(int s, int d, int sum) {
    if(d == 3) return 0;
    int ret = 0;
    for(int i = 0; i < (int)vs.size(); i++) {
        int v = vs[i].first, w = vs[i].second, ns = v * w + sum;
        if(w == 2 and ns < 100) ret++;
        if(i >= s) ret += dfs(i, d+1, ns);
    }
    return ret;
}

void solve() {
    rep(i,20) rep(j,3) vs.emplace_back(i+1, j+1);
    vs.emplace_back(25, 1); vs.emplace_back(25, 2);
    cout << dfs(0,0,0) << endl;
}

void input() {
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
