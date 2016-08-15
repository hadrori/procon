#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int inf = 1e9;

struct edge { int to, cap, rev; };
struct max_flow {
    int V;
    vector<vector<edge>> G;
    vector<int> itr, level;

    max_flow(){}
    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int run(int s, int t) {
        int ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V,0);
            while ((f = dfs(s, t, inf)) > 0) ret += f;
        }
        return ret;
    }

    void dump() {
        rep(i,V) {
            cerr << i/2 << " : " << endl;
            for(auto &e: G[i]) cerr << '\t' << e.to/2 << ' ' << e.cap << endl;
        }
    }
};

int n, m, e, p[128];
max_flow mf;

void solve() {
    int s = 0, t = n;
    rep(i,m) mf.add_edge(p[i],t,1);
    cout << mf.run(s,t) << endl;
}

void input() {
    cin >> n >> m >> e;
    rep(i,m) cin >> p[i];
    mf = max_flow(n+1);
    rep(i,e) {
        int a, b; cin >> a >> b;
        mf.add_edge(a,b,1);
        mf.add_edge(b,a,1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
