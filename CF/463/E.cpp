#include <bits/stdc++.h>
using namespace std;

int n, q, val[100010], par[100010], done[100010];
int notp[2000010];
vector<int> ps;

void genp()
{
        notp[0] = notp[1] = 1;
        for (int i = 0; i*i < 2000001; i++) {
                if(notp[i]) continue;
                ps.push_back(i);
                for (int j = i+i; j < 2000001; j+=i) notp[j] = 1;
        }
}

void dfs(int v, vector<int> &prm)
{
        
}

void prepare()
{
        vector<int> prm;
        dfs(0,prm);
}

void update(int v, int w)
{
}

int query(int v)
{
}

void solve()
{
        prepare();
        int t, v, w;
        while(q--){
                scanf("%d%d", &t, &v); v--;
                if(t == 1) cout << query(v)+1 << endl;
                else {
                        scanf("%d", &w);
                        update(v, w);
                }
        }
}

void input()
{
        genp();
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; i++) scanf("%d", val+i);
        int u, v;
        for (int i = 0; i < n-1; i++) {
                scanf("%d%d", &u, &v);
                u--; v--;
                G[u].push_back(v);
                G[v].push_back(u);
        }
}

int main()
{
        input();
        solve();
        return 0;
}
