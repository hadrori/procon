#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};
struct node { int i, j, v, d; };

int h, w, f[8][8], g[8][8][8];
inline bool in(int i, int j) { return i>=0 and j>=0 and i<h and j<w; }

int solve()
{
    memset(g,-1,sizeof(g));
    queue<node> q;
    rep(i,h) rep(j,w) if(f[i][j] == 2) q.push((node){i,j,6,0});
    while(q.size()) {
        node n = q.front(); q.pop();
        if(!n.v or !f[n.i][n.j]) continue;
        if(f[n.i][n.j] == 3) return n.d;
        if(f[n.i][n.j] == 4) n.v = 6;
        if(~g[n.i][n.j][n.v]) continue;
        g[n.i][n.j][n.v] = n.d;
        rep(d,4) {
            int ni = n.i+di[d], nj = n.j+dj[d];
            if(in(ni,nj)) q.push((node){ni,nj,n.v-1,n.d+1});
        }
    }
    return -1;
}

bool input()
{
    cin >> w >> h;
    rep(i,h) rep(j,w) cin >> f[i][j];
    return w or h;
}

int main()
{
    while(input()) printf("%d\n", solve());
    return 0;
}
