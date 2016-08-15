#include <bits/stdc++.h>
using namespace std;

const int di[] = {1,0,-1,0}, dj[] = {0,1,0,-1};

struct node
{
    int i, j, dir, d;
    node(int i, int j, int dir, int d) : i(i), j(j), dir(dir), d(d) {}
    bool operator<(const node &v) const { return d > v.d; }
};

int h, w;
char f[64][64];
bool done[64][64][4];

int solve()
{
    int si = -1, sj = -1, ti = -1, tj = -1, dir = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(string("v>^<").find(f[i][j]) != string::npos) {
                si = i;
                sj = j;
                dir = string("v>^<").find(f[i][j]);
            }
            if(f[i][j] == 'G') {
                ti = i;
                tj = j;
            }
        }
    }

    priority_queue<node> q;
    q.push(node(si,sj,dir,0));
    while(!q.empty()) {
        node v = q.top(); q.pop();
        bool g = 1;
        for (int d = 0; d < 4; d++) g &= !done[v.i][v.j][d];
        v.d += g;
        if(v.i == ti and v.j == tj) return v.d;
        if(done[v.i][v.j][v.dir]) continue;
        done[v.i][v.j][v.dir] = 1;
        const int ri = v.i+di[(v.dir+3)%4], rj = v.j+dj[(v.dir+3)%4];
        if(f[ri][rj] != '#') {
            q.push(node(ri,rj,(v.dir+3)%4,v.d));
            continue;
        }
        const int ni = v.i+di[v.dir], nj = v.j+dj[v.dir];
        if(f[ni][nj] != '#') q.push(node(ni,nj,v.dir,v.d));
        else q.push(node(v.i,v.j,(v.dir+1)%4,v.d));
     }
    return -1;
}

void input()
{
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", f[i+1]+1);
        f[i+1][0] = '#';
        f[i+1][w+1] = '#';
    }
    for (int j = 0; j < w+2; j++) f[0][j] = f[h+1][j] = '#';
    h += 2;
    w += 2;
}

int main()
{
    input();
    printf("%d\n", solve());
    return 0;
}
