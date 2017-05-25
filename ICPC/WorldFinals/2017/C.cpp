#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int MAX_V = 256;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v) {
    used[v] = 1;
    rep(i,G[v].size()) {
        int u = G[v][i], w = match[u];
        if(w < 0 || !used[w] && dfs(w)) {
            match[v] = u;
            match[u] = v;
            return 1;
        }
    }
    return 0;
}

int bi_matching() {
    int res = 0;
    memset(match, -1, sizeof(match));
    rep(v,V) if(match[v] < 0) {
        memset(used, 0, sizeof(used));
        if(dfs(v)) res++;
    }
    return res;
}

int h, w, f[128][128], r[128], c[128];

i64 solve() {
    V = h+w;
    rep(i,h) rep(j,w) {
        r[i] = max(r[i], f[i][j]);
        c[j] = max(c[j], f[i][j]);
    }
    rep(i,h) rep(j,w) if(f[i][j] && r[i] == c[j]) add_edge(i, j+h);
    bi_matching();
    i64 sum = 0, res = 0;
    rep(i,h) rep(j,w) sum += f[i][j];
    rep(i,h) rep(j,w) if(f[i][j]) res++;
    rep(j,w) if(c[j]) res += c[j] - 1;
    rep(i,h) if(r[i] && match[i] < 0) res += r[i] - 1;
    return sum - res;
}

void input() {
    cin >> h >> w;
    rep(i,h) rep(j,w) cin >> f[i][j];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
