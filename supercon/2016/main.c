#include <stdio.h>
#include <stdlib.h>
#include "macro.c"
#include "annealing.c"

void input(int &n, int &d, int &c, int *col, g_type *cc) {
    scanf("%d", &n);
    scanf("%d", &d);
    scanf("%d", &c);
    col = (int *)malloc(sizeof(int)*c);
    cc = (g_type *)malloc(sizeof(g_type)*c*c);
    rep(i,C) scanf("%d", col+i);
    rep(i,C-1) col[i+1] += col[i];
    rep(i,C) rep(j,C) scanf("%d", cc+i*C+j);
}

void output(int n, int *G) {
    rep(i,n) repi(j,i+1,n) if(G[at(i,j,n)]) printf("%d %d\n", i, j);
}

void gen_graph(int n, int d, int c, int *col, g_type *cc, g_type *G, int *to) {
    srand(time(0));
    int dm[N], vs[N], used[N], m = n, l = 0, r = 1;
    rep(i,n) vs[i] = i, dm[i] = 0;
    used[0] = rand()%n; r = 1;
    rep(_,n-1) {
        int p, q, v, w;
        do {
            p = rand()%m; q = rand()%(r-l)+l;
            v = vs[p]; w = used[q];
        } while(G[v*n+w] < inf);
        G[v*n+w] = G[w*n+v] = cc[color(v,col)*C+color(w,col)];
        swap(vs+p, vs+m-1); m--;
        used[r++] = v;
        dm[v]++; dm[w]++;
        if(dm[w] == d) { swap(used+q, used+l); l++; }
    }
    while(r - l > 0) {
        int p, q, v, w;
        do {
            p = rand()%(r-l)+l; q = rand()%(r-l)+l;
            v = used[p]; w = used[q];
        } while(v == w || G[v*n+w] < inf);
        G[v*n+w] = G[w*n+v] = cc[color(v,col)*C+color(w,col)];
        to[v*n+dm[v]] = w;
        to[w*n+dm[w]] = v;
        dm[v]++; dm[w]++;
        if(dm[v] == d) { swap(used+p, used+l); l++; }
        if(dm[w] == d) { swap(used+q, used+l); l++; }
    }
}

void solve() {
    int n, d, c, *col, *to;
    g_type *G, *H, *cc;
    input(n,d,c,col,cc);
    G = (g_type *)malloc(sizeof(g_type)*n*n);
    to = (g_type *)malloc(sizeof(int)*n*d);
    rep(i,n*n) G[i] = INF;
    rep(i,n) G[at(i,i,n)] = 0;
    gen_graph(n, d, c, col, cc, G, to);
    annealing(n, d, c, col, cc. G, H, to);
    
}

int main() {
    solve();
    return 0;
}
