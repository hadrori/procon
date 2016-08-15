#include <bits/stdc++.h>
using namespace std;

struct info
{
        int v, ld, sum;
        info(){}
        info(int v, int ld, int sum) : v(v), ld(ld), sum(sum) {}
};

int n, p[1024], d[1024], to[2];
vector<pair<int,int>> G[1024];

info dfs(int u, int v)
{
        info ret(v,0,0);
        for(auto &e: G[v]) {
                if(e.first == u) continue;
                info tmp = dfs(v, e.first);
                if(!tmp.ld) tmp.ld = e.second;
                if(tmp.sum+e.second > ret.sum) {
                        ret = tmp;
                        ret.sum += e.second;
                }
                else if(tmp.sum+e.second == ret.sum) {
                        if(ret.ld < tmp.ld) {
                                ret.v = tmp.v;
                                ret.ld = tmp.ld;
                        }
                }
        }
        return ret;
}

int leaf(int u, int v)
{
        int ret = 0;
        for(auto &e: G[v]) {
                if(e.first == u) continue;
                int tmp = leaf(v, e.first);
                if(!tmp) ret += e.second;
                else ret += tmp;
        }
        return ret;
}

int solve()
{
        for (int i = 0; i < n; i++) G[i].clear();
        int sum = accumulate(d+1, d+n, 0)*3;
        for (int i = 1; i < n; i++) {
                G[i].push_back(make_pair(p[i]-1, d[i]));
                G[p[i]-1].push_back(make_pair(i, d[i]));
        }
        info a = dfs(-1,0), b = dfs(-1,a.v);
        cerr << a.v << ' ' << a.ld << ' ' << a.sum << endl;
        cerr << b.v << ' ' << b.ld << ' ' << b.sum << endl;
        return sum-leaf(-1,a.v)-b.sum-a.ld;
}

bool input()
{
        scanf("%d", &n);
        for (int i = 1; i < n; i++) scanf("%d", p+i);
                
        for (int i = 1; i < n; i++) scanf("%d", d+i);
        return n;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
