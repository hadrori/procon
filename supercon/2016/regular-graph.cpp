namespace rgraph {

void generate(int *to, int n, int d) {
    srand(time(0));
    std::vector<int> res, added;
    std::vector<std::vector<int>> g(n,std::vector<int>(n)), t2(n);
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
    rep(i,n) rep(j,n)
        if(!g[i][j] && (int)t2[i].size() < d && (int)t2[j].size() < d)
            es.emplace_back(i, j);

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

}
