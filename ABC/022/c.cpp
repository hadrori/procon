#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
inline void chmin(int &x, int y) { if(x < 0) x = y; else if(y >= 0) x = min(x, y); }

int n, m, done[512];

vector<pair<int,int>> G[512];

int calc(int s, int d) {
    memset(done,0,sizeof(done));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.emplace(d,s);
    int v;
    while(!q.empty()) {
        tie(d,v) = q.top(); q.pop();
        if(!v) return d;
        if(done[v]) continue;
        done[v] = 1;
        for (auto &p: G[v]) if(p.first or v != s) q.emplace(d+p.second,p.first);
    }
    return -1;
}

void solve() {
    int ans = -1;
    rep(i,G[0].size()) chmin(ans, calc(G[0][i].first, G[0][i].second));
    cout << ans << endl;
}

void input() {
    cin >> n >> m;
    rep(i,m) {
        int u, v, l;
        cin >> u >> v >> l; u--; v--;
        G[u].emplace_back(v,l);
        G[v].emplace_back(u,l);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
