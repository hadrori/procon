#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

using graph = vector<vector<int>>;
class tree {
    graph G;
    int root, V, logV;
    vector<vector<int>> par;
    vector<int> dep;

    void dfs(int v, int u) {
        if(~u) {
            dep[v] = dep[u]+1;
            par[v][0] = u;
            int k = 0;
            while(par[par[v][k]][k] >= 0) {
                par[v][k+1] = par[par[v][k]][k];
                k++;
            }
        }
        for(int &w: G[v]) if(w != u) dfs(w,v);
    }

public:
    tree() {}
    tree(const graph &G, int root = 0) : G(G), root(root) {
        V = G.size();
        logV = 1;
        while((1<<logV) < V) logV++;
        dep.assign(V,0);
        par.assign(V,vector<int>(logV,-1));
        dfs(root,-1);
    }

    int lca(int u, int v) {
        if(dep[u] > dep[v]) swap(u,v);
        int diff = dep[v]-dep[u];
        for(int i = 0; i < logV; i++)
            if(diff&(1<<i)) v = par[v][i];
        if(u == v) return u;
        for(int i = logV-1; i >= 0; i--)
            if(par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        return par[u][0];
    }

    int dist(int u, int v) { return dep[u]+dep[v]-2*dep[lca(u,v)]; }
};


int n, m;
graph G;
tree tr;

void solve() {
    tr = tree(G);
    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << tr.dist(a-1,b-1)+1 << endl;
    }
}

void input() {
    cin >> n;
    G.assign(n,vector<int>());
    int x, y;
    rep(i,n-1) {
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin >> m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
