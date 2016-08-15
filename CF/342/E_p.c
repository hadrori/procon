#include "stdio.h"
#include "string.h"
#include "sys/time.h"
#include "mpi.h"

double sec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

#define N 100000
#define B 317
#define min(x,y) ((x)>(y)?(y):(x))

struct edge { int u, v; } es[N], qs[N];
int n, q, cnt[N], pos[N+1], ans[N], to[2*N], par[N][18], dep[N], red[N], dist[N];

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

void send_init(int pid) {
    MPI_Send(&n, 1, MPI_INT, pid, 1, MPI_COMM_WORLD);
    MPI_Send(&q, 1, MPI_INT, pid, 2, MPI_COMM_WORLD);
    MPI_Send(qs, q, MPI_LONG, pid, 3, MPI_COMM_WORLD);
    MPI_Send(pos, n+1, MPI_INT, pid, 4, MPI_COMM_WORLD);
    MPI_Send(to, pos[n], MPI_INT, pid, 5, MPI_COMM_WORLD);
    MPI_Send(par, n*18, MPI_INT, pid, 6, MPI_COMM_WORLD);
    MPI_Send(dep, n, MPI_INT, pid, 7, MPI_COMM_WORLD);
}

void recv_init() {
    MPI_Status stat;
    MPI_Recv(&n, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &stat);
    MPI_Recv(&q, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, &stat);
    MPI_Recv(qs, q, MPI_LONG, 0, 3, MPI_COMM_WORLD, &stat);
    MPI_Recv(pos, n+1, MPI_INT, 0, 4, MPI_COMM_WORLD, &stat);
    MPI_Recv(to, pos[n], MPI_INT, 0, 5, MPI_COMM_WORLD, &stat);
    MPI_Recv(par, n*18, MPI_INT, 0, 6, MPI_COMM_WORLD, &stat);
    MPI_Recv(dep, n, MPI_INT, 0, 7, MPI_COMM_WORLD, &stat);
}

double solve_parallel(int rank, int size) {
    int i, b, j;
    for (b = (rank-1)*B; b < q; b += B*(size-1)) {
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
        MPI_Send(ans+b, min(B,q-b), MPI_INT, 0, b, MPI_COMM_WORLD);
    }
}

void solve() {
    int i, b, j;
    
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


int main(int argc, char* argv[]) {
    int i, b, j;
    int rank, size;
    input();
    pos[0] = 0;
    for (i = 0; i < n; i++) pos[i+1] = pos[i]+cnt[i];
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < n-1; i++) {
        int u = es[i].u, v = es[i].v;
        to[pos[u]+cnt[u]++] = v;
        to[pos[v]+cnt[v]++] = u;
    }
    memset(par, -1, sizeof(par));
    dfs(0,-1);

    double s = sec(), t;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    memset(red, 0, sizeof(red));
    red[0] = 1;
    if(!rank) {
        double ps = sec();
        for (i = 1; i < size; i++) send_init(i);
        MPI_Status stat;
        for (i = 0; i*B < q; i++)
            MPI_Recv(ans+i*B,
                     min((i+1)*B,q)-i*B,
                     MPI_INT,
                     i%(size-1)+1,
                     i*B,
                     MPI_COMM_WORLD,
                     &stat);
        printf("parallel     : %.8f s\n", sec()-ps);
        int t_ans[N];
        memcpy(t_ans, ans, sizeof(ans));
        double s = sec();
        solve();
        printf("not parallel : %.8f s\n", sec()-s);
        int ok = 1;
        for(i = 0; i < q; i++) if(qs[i].u && t_ans[i] != ans[i]) {
                ok = 0;
                break;
            }
        puts(ok? "Correct": "Wrong Answer");
        for(i = 0; i < q; i++) if(qs[i].u) printf("%d ", ans[i]);
        puts("");
    }
    else {
        recv_init();
        solve_parallel(rank, size);
    }
    MPI_Finalize();

    return 0;
}
