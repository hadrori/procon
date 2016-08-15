#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int inf = 1e9;
struct edge {
    int to, cap, cost, rev;
    edge(int to, int cap, int cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
};
typedef vector<vector<edge> > graph;

void add_edge(graph& G, int from, int to, int cap, int cost) {
    G[from].push_back(edge(to, cap, cost, G[to].size()));
    G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
}

int min_cost_flow(graph& G, int s, int t, int f) {
    const int n = G.size();
    struct state {
        int v, d;
        state(int v, int d) : v(v), d(d) {}
        bool operator <(const state& t) const { return d > t.d; }
    };

    int ret = 0;
    vector<int> h(n, 0), dist, prev(n), prev_e(n);
    while (f > 0) {
        dist.assign(n, inf);
        priority_queue<state> q;
        dist[s] = 0, q.emplace(s, 0);
        while (not q.empty()) {
            const int v = q.top().v;
            const int d = q.top().d;
            q.pop();
            if (dist[v] < d) continue;
            rep(i, G[v].size()) {
                const edge& e = G[v][i];
                if (e.cap > 0 and dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prev[e.to] = v, prev_e[e.to] = i;
                    q.emplace(e.to, dist[e.to]);
                }
            }
        }
        if (dist[t] == inf) return -1;
        rep(i, n) h[i] += dist[i];

        int d = f;
        for (int v = t; v != s; v = prev[v]) {
            d = min(d, G[prev[v]][prev_e[v]].cap);
        }
        f -= d, ret += d * h[t];
        for (int v = t; v != s; v = prev[v]) {
            edge& e = G[prev[v]][prev_e[v]];
            e.cap -= d, G[v][e.rev].cap += d;
        }
    }
    return ret;
}

int n, a[1024], b[1024];
graph G;
map<int,int> cid;

int solve()
{
    int s = n, t;
    rep(i,n) if(!cid.count(a[i])) cid[a[i]] = s++;
    rep(i,n) if(!cid.count(b[i])) cid[b[i]] = s++;
    s++;
    t = s+1;
    G.assign(t+1,vector<edge>());
    rep(i,n) add_edge(G, s, i, 1, 0);
    rep(i,n) {
        add_edge(G, i, cid[a[i]], 1, -b[i]);
        add_edge(G, i, cid[b[i]], 1, -a[i]);
        add_edge(G, i, s-1, 1, 0);
    }
    repi(i,n,s-1) add_edge(G, i, t, 1, 0);
    add_edge(G, s-1, t, inf, 0);
    return -min_cost_flow(G, s, t, n);
}

void input()
{
    cin >> n;
    rep(i,n) cin >> a[i] >> b[i];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
