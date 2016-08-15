#include <bits/stdc++.h>
using namespace std;

int n, c[1024];
vector<pair<int,int>> g[1024];

int solve(int u, int v)
{
    int sum = 0;
    for(auto &e: g[v]) {
        if(e.first == u) continue;
        if(c[e.first]) {
            sum += e.second;
            continue;
        }
        sum += min(e.second, solve(v,e.first));
    }
    return sum;
}

void input()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) scanf("%d", c+i);
    int u, v, p;
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d%d", &u, &v, &p);
        g[u].push_back(make_pair(v,p));
        g[v].push_back(make_pair(u,p));
    }
}

int main()
{
    input();
    cout << solve(-1,0) << endl;
    return 0;
}
