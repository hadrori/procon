#include <bits/stdc++.h>

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define INF 1e8

#include "regular-graph.cpp"
#include "annealing.cpp"

using namespace std;

void input_arr(int *arr, int n) {
    arr = (int *)malloc(sizeof(int)*n);
    rep(i,n) scanf("%d", arr+i);
}
int input_int() { int n; scanf("%d", &n); return n; }

int color(int k, int *col) { return k < col[0] ? 0 : k < col[1] ? 1 : 2; }

void gen_graph(int *G, int *to, int *col, int *dist, int n, int d, int c) {
    rgraph::generate(to, n, d);
    rep(i,n*n) G[i] = INF;
    rep(i,n) G[i*n+i] = 0;
    rep(i,n) rep(j,d) G[i*n+to[i*d+j]] = dist[color(i,col)*c+color(to[i*d+j],col)];
}

void output(int *G, int n) {
    rep(i,n) repi(j,i+1,n) if(G[i*n+j] < INF) printf("%d %d\n", i, j);
}

void solve() {
    int n = input_int(), d = input_int(), c = input_int();
    int *A, *to, *col, *dist;
    A    = (int *)malloc(sizeof(int)*n*n);
    to   = (int *)malloc(sizeof(int)*n*d);
    col  = (int *)malloc(sizeof(int)*c);
    dist = (int *)malloc(sizeof(int)*c*c);
    input_arr(col, c); input_arr(dist, c*c);
    rep(i,c-1) col[i+1] += col[i];

    gen_graph(A, to, col, dist, n, d, c);
    annealing::run(A, to, col, dist, n, d, c);
    output(A, n);
}

int main() {
    solve();
    return 0;
}
