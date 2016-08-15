#include <bits/stdc++.h>
using namespace std;

int n, idx, done[256];
map<string, int> id;
vector<pair<int,int>> G[256];

int dfs(int v, int w, int y, int sum)
{
        if(done[v]) return 1;
        done[v] = 1;
        if(v == w) return sum == y;
        for(auto &e: G[v]) if(!dfs(e.first, w, y, sum+e.second)) return 0;
        return 1;
}

int solve()
{
        idx = 0;
        bool ok = 1;
        while(n--) {
                int x;
                string s, t, u, _;
                cin >> _ >> s >> _ >> u >> t;
                x = atoi(u.substr(3).c_str());
                if(!ok) continue;
                if(!id.count(s)) id[s] = idx++;
                if(!id.count(t)) id[t] = idx++;

                memset(done,0,sizeof(done));
                int from = id[s], to = id[t];
                if(!dfs(from, to, x, 0)) ok = 0;
                else {
                        G[from].push_back(make_pair(to,x));
                        G[to].push_back(make_pair(from,-x));
                }
        }
        return ok;
}

bool input()
{
        id.clear();
        for (int i = 0; i < 256; i++) G[i].clear();
        scanf("%d", &n);
        return n;
}

int main()
{
        while(input()) puts(solve()? "Yes": "No");
        return 0;
}
