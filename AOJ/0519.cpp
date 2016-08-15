#include <bits/stdc++.h>
using namespace std;

int n, m, done[5010];
vector<int> G[5010], vs;

void t_dfs(int v)
{
        if(done[v]) return;
        done[v] = 1;
        for(auto &u: G[v]) t_dfs(u);
        vs.push_back(v);
}

void solve()
{
        for (int i = 0; i < n; i++) t_dfs(i);
        reverse(begin(vs),end(vs));
        for(auto &v: vs) printf("%d\n", v+1);
        for (int i = 0; i < n-1; i++) {
                bool ok = 0;
                for(auto &e: G[vs[i]])
                        if(e == vs[i+1]) {
                                ok = 1;
                                break;
                        }
                if(!ok) {
                        puts("1");
                        return;
                }
        }
        puts("0");
}

void input()
{
        scanf("%d%d", &n, &m);
        int a, b;
        for (int i = 0; i < m; i++) {
                scanf("%d%d", &a, &b);
                a--; b--;
                G[a].push_back(b);
        }
}

int main()
{
        input();
        solve();
        return 0;
}
