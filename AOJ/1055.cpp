#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

inline void chmin(int &x, int y) { x < 0? y: min(x,y); }
int n, G[100010][2], w[100010][2], used[100010];

int bfs(int v)
{
    int x = -1, y = 0;
    queue<int> q;
    q.push(v);
    while(q.size()) {
        v = q.front(); q.pop();
        if(used[v]) continue;
        used[v] = 1;
        rep(i,2) {
            if(w[v][i] > x) {
                x = w[v][i];
                y = 1;
            }
            else if(w[v][i] == x) y++;
            q.push(G[v][i]);
        }
    }
    return y/2;
}

int solve()
{
    memset(used,0,sizeof(used));
    long long ans = 0;
    rep(i,n) if(!used[i]) {
        int tmp = bfs(i);
        ans = ans? ans*tmp: tmp;
        ans %= 10007;
    }
    return ans;
}

bool input()
{
    scanf("%d", &n);
    rep(i,n) scanf("%d%d%d%d", G[i], w[i], G[i]+1, w[i]+1);
    return n;
}

int main()
{
    while(input()) printf("%d\n", solve());
    return 0;
}
