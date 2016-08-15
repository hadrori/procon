#include "stdio.h"
#include "string.h"

#define N 100000
#define B 317
#define min(x,y) ((x)>(y)?(y):(x))

struct edge { int u, v; } es[N], qs[N];
int n, q, cnt[N], pos[2*N], ans[N], to[2*N], par[N][18], dep[N], red[N], dist[N];

void dfs(int v, int pv) {
    int i, k;
    if(~pv) dep[v] = dep[pv]+1;
    par[v][0] = pv;
    for (k = 0; ~par[v][k] && ~par[par[v][k]][k]; k++) par[v][k+1] = par[par[v][k]][k];
    for (i = pos[v]; i < pos[v+1]; i++) if(to[i] != pv) dfs(to[i], v);
}

int lca(int u, int v) {
    if(dep[u] > dep[v]) return lca(v,u);
    int dif = dep[v] - dep[u], i;
    for (i = 0; i < 18; i++) if(dif&(1<<i)) v = par[v][i];
    if(u == v) return u;
    for (i = 17; i >= 0; i--) 
        if(par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

void bfs(int m) {
    int que[N], l = 0, r = 0, v, i;
    memset(dist, -1, sizeof(dist));
    que[r++] = 0;
    dist[0] = 0;
    for (i = 0; i < m; i++) if(!qs[i].u) {
        que[r++] = qs[i].v;
        dist[qs[i].v] = 0;
    }
    while(l < r) {
        v = que[l++];
        for (i = pos[v]; i < pos[v+1]; i++) if(dist[to[i]] < 0) {
            que[r++] = to[i];
            dist[to[i]] = dist[v]+1;
        }
    }
}

void solve() {
    int i, b, j;
    for (i = 0; i < n; i++) pos[i+1] = pos[i]+cnt[i];
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < n-1; i++) {
        int u = es[i].u, v = es[i].v;
        to[pos[u]+cnt[u]++] = v;
        to[pos[v]+cnt[v]++] = u;
    }
    memset(par, -1, sizeof(par));
    memset(ans, -1, sizeof(ans));
    red[0] = 1;
    dfs(0,-1);

    for (b = 0; b < q; b += B) {
        for (i = 0; i < b; i++) if(!qs[i].u) red[qs[i].v] = 1;
        bfs(b);
        int m = 0, vs[B];
        for (i = b; i < min(b+B, q); i++) {
            if(!qs[i].u) vs[m++] = qs[i].v;
            else {
                ans[i] = dist[qs[i].v];
                for (j = 0; j < m; j++) ans[i] = min(ans[i], dep[vs[j]]+dep[qs[i].v]-2*dep[lca(vs[j], qs[i].v)]);
            }
        }
    }
    for (i = 0; i < q; i++) if(~ans[i]) printf("%d\n", ans[i]);
}

void input() {
    scanf("%d %d", &n, &q);
    int u, v, i;
    for (i = 0; i < n-1; i++) {
        scanf("%d %d", &u, &v);
        es[i].u = --u;
        es[i].v = --v;
        cnt[u]++; cnt[v]++;
    }
    for (i = 0; i < q; i++) {
        scanf("%d %d", &u, &v);
        qs[i].u = --u;
        qs[i].v = --v;
    }
}

int main() {
    input();
    solve();
    return 0;
}
