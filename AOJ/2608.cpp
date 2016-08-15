#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
long long cs[100010], ct[100010], ds[100010], dt[100010];
vector<int> G[100010];

void calc(int from, long long dist[], long long cnt[])
{
        memset(dist,-1,sizeof(cs));
        memset(cnt,0,sizeof(cs));
        queue<int> q;
        dist[from] = 0;
        cnt[0]++;
        q.push(from);
        while(!q.empty()) {
                int v = q.front(); q.pop();
                for(auto &e: G[v]) {
                        if(dist[e] >= 0) continue;
                        dist[e] = dist[v]+1;
                        cnt[dist[e]]++;
                        q.push(e);
                }
        }
}

long long solve()
{
        calc(s,ds,cs);
        calc(t,dt,ct);
        long long ans = 0;
        for (int i = 0; i < ds[t]-1; i++) ans += cs[i]*ct[ds[t]-i-2];
        return ans;
}

void input()
{
        scanf("%d%d%d%d", &n, &m, &s, &t);
        s--; t--;
        for (int i = 0; i < m; i++) {
                int x, y; scanf("%d%d", &x, &y);
                x--; y--;
                G[x].push_back(y);
                G[y].push_back(x);
        }
}

signed main()
{
        input();
        printf("%lld\n", solve());
        return 0;
}
