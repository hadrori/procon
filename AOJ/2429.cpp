#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
struct min_cost_flow {

        struct edge { int to, cap, cost, rev;};

        vector<vector<edge>> G;
        int n;
        min_cost_flow() {}
        min_cost_flow(int n) : n(n) {
                G.assign(n,vector<edge>());
        }

        void add_edge(int from, int to, int cap, int cost) {
                G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
                G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
        }

        int run(int s, int t, int f) {
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
                        dist[s] = 0; q.push(state(s, 0));
                        while (!q.empty()) {
                                const int v = q.top().v, d = q.top().d;
                                q.pop();
                                if (dist[v] < d) continue;
                                for (int i = 0; i < (int)G[v].size(); i++) {
                                        const edge &e = G[v][i];
                                        if (e.cap > 0 and dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                                                dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                                                prev[e.to] = v;
                                                prev_e[e.to] = i;
                                                q.push(state(e.to, dist[e.to]));
                                        }
                                }
                        }
                        if (dist[t] == inf) return -1;
                        for (int i = 0; i < n; i++) h[i] += dist[i];

                        int d = f;
                        for (int v = t; v != s; v = prev[v]) d = min(d, G[prev[v]][prev_e[v]].cap);

                        f -= d;
                        ret += d * h[t];
                        for (int v = t; v != s; v = prev[v]) {
                                edge &e = G[prev[v]][prev_e[v]];
                                e.cap -= d;
                                G[v][e.rev].cap += d;
                        }
                }
                return ret;
        }
};

int wc[128][128], ec[128][128], n;
char f[128][128];

void solve()
{
        min_cost_flow mf(2*n+2);
        const int s = 2*n, t = s+1;

        for (int i = 0; i < n; i++) {
                mf.add_edge(s,i,1,0);
                mf.add_edge(n+i,t,1,0);
                int sum = 0;
                for (int j = 0; j < n; j++) if(f[i][j] == 'o') sum += ec[i][j];
                for (int j = 0; j < n; j++) {
                        if(f[i][j] == 'o') mf.add_edge(i,n+j,1,sum-ec[i][j]);
                        else mf.add_edge(i,n+j,1,wc[i][j]+sum);
                }
        }

        int cst = mf.run(s,t,n);
        vector<int> is, js;
        vector<string> cs;
        for(int i = 0; i < n; i++) {
                for(auto &e: mf.G[i]) {
                        int j = e.to-n;
                        if(j == n) continue;
                        if(f[i][j] == 'o' and e.cap) {
                                is.push_back(i);
                                js.push_back(j);
                                cs.push_back("erase");
                        }
                        else if(f[i][j] == '.' and !e.cap) {
                                is.push_back(i);
                                js.push_back(j);
                                cs.push_back("write");
                        }
                }
        }
        
        printf("%d\n%d\n", cst, (int)is.size());
        for (int i = 0; i < (int)is.size(); i++) {
                printf("%d %d %s\n", is[i]+1, js[i]+1, cs[i].c_str());
        }
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        scanf("%d", wc[i]+j);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        scanf("%d", ec[i]+j);
        for (int i = 0; i < n; i++) scanf("%s", f[i]);
}

int main()
{
        input();
        solve();
        return 0;
}
