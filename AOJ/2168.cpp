#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
struct max_flow
{
        struct edge { int to, cap, rev; };
        int V;
        vector<vector<edge>> G;
        vector<int> itr, level;

        max_flow(int V) : V(V) { G.assign(V,vector<edge>());}

        void add_edge(int from, int to, int cap) {
                G[from].push_back((edge) {to, cap, (int) G[to].size()});
                G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
        }

        void bfs(int s) {
                level.assign(V,-1);
                queue<int> q;
                level[s] = 0; q.push(s);
                while (!q.empty()) {
                        int v = q.front(); q.pop();
                        for(auto &e: G[v]){
                                if (e.cap > 0 and level[e.to] < 0) {
                                        level[e.to] = level[v] + 1;
                                        q.push(e.to);
                                }
                        }
                }
        }

        int dfs(int v, int t, int f) {
                if (v == t) return f;
                for (int& i = itr[v]; i < (int) G[v].size(); ++i) {
                        edge& e = G[v][i];
                        if (e.cap > 0 and level[v] < level[e.to]) {
                                int d = dfs(e.to, t, min(f, e.cap));
                                if (d > 0) {
                                        e.cap -= d;
                                        G[e.to][e.rev].cap += d;
                                        return d;
                                }
                        }
                }
                return 0;
        }

        int run(int s, int t) {
                int ret = 0, f;
                while (bfs(s), level[t] >= 0) {
                        itr.assign(V,0);
                        while ((f = dfs(s, t, inf)) > 0) ret += f;
                }
                return ret;
        }
};

int h, w, c, m, nw, nc, nm;
int f[4][64][64];

int solve()
{
        max_flow mf(h+2*w+2*c+m+7);
        int s = h+2*w+2*c+m+5, t = s+1;

        for (int i = 0; i < h; i++) {
                mf.add_edge(s,i,1);
                for (int j = 0; j < w; j++) if(f[0][i][j]) mf.add_edge(i,h+j,1);
                mf.add_edge(i,h+w,1);
        }
        mf.add_edge(h+w,h+2*w+1,nw);
        for (int i = 0; i < w; i++) {
                mf.add_edge(h+i,h+w+1+i,1);
                for (int j = 0; j < c; j++) if(f[1][i][j]) mf.add_edge(h+w+1+i,h+2*w+2+j,1);
                mf.add_edge(h+w+1+i,h+2*w+c+2,1);
        }
        mf.add_edge(h+2*w+c+2,h+2*w+2*c+3,nc);
        for (int i = 0; i < c; i++) {
                mf.add_edge(h+2*w+1,h+2*w+2+i,1);
                mf.add_edge(h+2*w+2+i,h+2*w+c+3+i,1);
                for (int j = 0; j < m; j++) if(f[2][i][j]) mf.add_edge(h+2*w+c+3+i,h+2*w+2*c+4+j,1);
                mf.add_edge(h+2*w+c+3+i,h+2*w+2*c+m+4,1);
        }
        mf.add_edge(h+2*w+2*c+m+4,t,nm);
        for (int i = 0; i < m; i++) {
                mf.add_edge(h+2*w+2*c+3,h+2*w+2*c+4+i,1);
                mf.add_edge(h+2*w+2*c+4+i,t,1);
        }

        return mf.run(s,t);
}

bool input()
{
        scanf("%d%d%d%d%d%d%d", &h, &w, &c, &m, &nw, &nc, &nm);
        memset(f,0,sizeof(f));
        for (int i = 0; i < w; i++) {
                int n, a; scanf("%d", &n);
                for (int j = 0; j < n; j++) {
                        scanf("%d", &a); a--;
                        f[0][a][i] = 1;
                }
        }
        for (int i = 0; i < c; i++) {
                int n, a; scanf("%d", &n);
                for (int j = 0; j < n; j++) {
                        scanf("%d", &a); a--;
                        f[1][a][i] = 1;
                }
        }
        for (int i = 0; i < m; i++) {
                int n, a; scanf("%d", &n);
                for (int j = 0; j < n; j++) {
                        scanf("%d", &a); a--;
                        f[2][a][i] = 1;
                }
        }

        return h >= 0;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
