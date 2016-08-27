namespace rgraph {

void __generate(int *to, int n, int d) {
    srand(1);
    std::vector<int> res, added;
    std::vector<std::vector<int>> g(n,std::vector<int>(n,0)), t2(n);
    rep(i,n) res.push_back(i), g[i][i] = 1;
    std::random_shuffle(std::begin(res), std::end(res));
    added.push_back(res.back());
    res.pop_back();
    rep(i,n-1) {
        int v = res.back(),
            q = rand()%added.size(),
            w = added[q];
        res.pop_back();
        added.push_back(v);
        t2[w].push_back(v); t2[v].push_back(w);
        g[v][w] = g[w][v] = 1;
        if((int)t2[w].size() == d) {
            std::swap(added[q], added.back());
            added.pop_back();
        }
    }
    std::vector<std::pair<int,int>> es;
    rep(i,added.size()) repi(j,i+1,added.size())
        if(!g[added[i]][added[j]]) es.emplace_back(added[i], added[j]);

    while(es.size()) {
        int v, w, p = rand()%es.size();
        std::swap(es[p], es.back());
        v = es.back().first, w = es.back().second;
        es.pop_back();
        if(g[v][w] || (int)t2[w].size() == d || (int)t2[v].size() == d) continue;
        g[v][w] = g[w][v] = 1;
        t2[v].push_back(w);
        t2[w].push_back(v);
    }
    rep(i,n) rep(j,d) to[i*d+j] = t2[i][j];
}

void gen_even(int *to, int n, int d) {
    std::vector<int> vs(n); rep(i,n) vs[i] = i;
    std::random_shuffle(std::begin(vs), std::end(vs));
    std::vector<std::pair<int,int>> es;
    rep(i,d+1) repi(j,i+1,d+1) es.emplace_back(vs[i],vs[j]);
    repi(i,d+1,n) {
        const int nv = vs[i];
        std::vector<int> used(n), cand;
        while((int)cand.size() < d) {
            int p = rand()%es.size();
            if(used[es[p].first] || used[es[p].second]) continue;
            cand.push_back(es[p].first);
            cand.push_back(es[p].second);
            std::swap(es[p], es.back());
            es.pop_back();
        }
        for (int &v: cand) es.emplace_back(nv, v);
    }
    std::vector<int> dm(n);
    for (auto &e: es) {
        to[e.first*d+dm[e.first]++] = e.second;
        to[e.second*d+dm[e.second]++] = e.first;
    }
}

int dfs(int v, int d, std::vector<int> &used, std::vector<int> &vs, std::vector<std::vector<int>> &t2) {
    if(used[v]) return 0;
    used[v] = 1;
    vs.push_back(v);
    if((int)vs.size() == d+1) return 1;
    rep(i,t2[v].size()) if(dfs(t2[v][i], d, used, vs, t2)) return 1;
    used[v] = 0;
    vs.pop_back();
    return 0;
}

int update(std::vector<std::vector<int>> &t2, int v, int from, int to) {
    rep(i,t2[v].size()) if(t2[v][i] == from) return t2[v][i] = to;
    return -1;
}

void gen_odd(int *to, int n, int d) {
    std::vector<int> vs(n); rep(i,n) vs[i] = i;
    std::vector<std::vector<int>> t2(n);
    std::random_shuffle(std::begin(vs), std::end(vs));
    rep(i,d+1) repi(j,i+1,d+1) {
        t2[vs[i]].push_back(vs[j]);
        t2[vs[j]].push_back(vs[i]);
    }
    reps(i,d+1,n,2) {
        const int nv = vs[i], nw = vs[i+1];
        std::vector<int> used(n);
        std::vector<int> ws;
        while(!dfs(rand()%i, d, used, ws, t2));
        rep(i,ws.size()) {
            const int v = ws[i];
            if(i < (int)ws.size()-1)  {
                t2[nv].push_back(v);
                update(t2, v, ws[i+1], nv);
            }
            if(i) {
                t2[nw].push_back(v);
                update(t2, v, ws[i-1], nw);
            }
        }
    }
    rep(i,n) printf("%d ", (int)t2[i].size());
    puts("");
    rep(i,n) {
        printf("%d : ", i);
        rep(j,d) printf("%d ", t2[i][j]);
        puts("");
    }
    rep(i,n) rep(j,d) to[i*d+j] = t2[i][j];
}

void generate(int *to, int n, int d) {
    srand(1);
    if(d%2) gen_odd(to, n, d);
    else gen_even(to, n, d);
}

}
