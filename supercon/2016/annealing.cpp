namespace annealing {

int color(int k, int *col) { return k < col[0] ? 0 : k < col[1] ? 1 : 2; }

int connected(int *to, int n, int d) {
    std::queue<int> q; std::vector<int> done(n);
    q.push(0);
    while(!q.empty()) {
        const int v = q.front(); q.pop();
        if(done[v]) continue;
        done[v] = 1;
        rep(i,d) q.push(to[v*d+i]);
    }
    rep(i,n) if(!done[i]) return 0;
    return 1;
}

int invalid(int *G, int *v, int n, int d) {
    return
        v[0] == v[1] ||
        v[0] == v[2] ||
        v[0] == v[3] ||
        v[1] == v[2] ||
        v[1] == v[3] ||
        v[2] == v[3] ||
        G[v[0]*n+v[3]] != INF ||
        G[v[1]*n+v[2]] != INF;
}

void modify(int *G, int *to, int *col, int *dist, int n, int d, int c, int *v) {
    do {
        v[0] = rand()%n; v[1] = to[v[0]*d+rand()%d];
        v[2] = rand()%n; v[3] = to[v[2]*d+rand()%d];
    } while(invalid(G, v, n, d));
    rep(k,4) rep(i,d) if(to[v[k]*d+i] == v[k^1]) to[v[k]*d+i] = v[3-k];
    rep(i,4) G[v[i]*n+v[i^1]] = INF;
    rep(i,4) G[v[i]*n+v[3-i]] = dist[color(v[i],col)*c+color(v[3-i],col)];
}

void revert(int *G, int *to, int *col, int *dist, int n, int d, int c, int *v) {
    rep(k,4) rep(i,d) if(to[v[k]*d+i] == v[3-k]) to[v[k]*d+i] = v[k^1];
    rep(i,4) G[v[i]*n+v[3-i]] = INF;
    rep(i,4) G[v[i]*n+v[i^1]] = dist[color(v[i],col)*c+color(v[i^1],col)];
}

int eval(int *G, int n) {
    int *H; H = (int *)malloc(sizeof(int)*n*n);
    rep(i,n*n) H[i] = G[i];
    rep(k,n) rep(i,n) rep(j,n) {
        if(i == j || i == k || j == k) continue;
        H[i*n+j] = std::min(H[i*n+j], H[i*n+k]+H[k*n+j]);
    }
    int sum = 0;
    rep(i,n*n) sum += H[i];
    free(H);
    return sum;
}

int valid(int *G, int n, int d) {
    rep(i,n) {
        int c = 0;
        rep(j,n) if(G[i*n+j] < INF) c++;
        if(c != d+1) return 0;
    }
    rep(i,n) repi(j,i+1,n) if(G[i*n+j] != G[j*n+i]) return 0;
    return 1;
}

void run(int *G, int *to, int *col, int *dist, int n, int d, int c) {
    double temp = 10000, cooler = 0.999;
    int aspl = eval(G, n), *v;
    v = (int *)malloc(sizeof(int)*4);
    while(temp > 0.001) {
        modify(G, to, col, dist, n, d, c, v);
        int res = eval(G, n);
        if(res < aspl) {
            aspl = res;
            printf("ASPL : %d\n", aspl);
        }
        else {
            double p = exp((aspl-res)/temp);
            if(rand()*1.0/RAND_MAX < p) aspl = res;
            else revert(G, to, col, dist, n, d, c, v);
        }
        temp *= cooler;
    }
    rep(i,n) {
        rep(j,n) {
            if(G[i*n+j] < INF) printf("%d ", G[i*n+j]);
            else printf("- ");
        }
        puts("");
    }
}

}
