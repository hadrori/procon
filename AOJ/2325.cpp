#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

struct node
{
        int i, j, dir, cst;
        node(int i, int j, int dir, int cst) : i(i), j(j), dir(dir), cst(cst) {}
        bool operator<(const node &v) const { return cst > v.cst; }
};

int h, w, n, dist[1024][1024][4];
char s[1<<20], f[1024][1024];
vector<int> dd[4];

inline bool ok(int i, int j) { return 0 <= i and i < h and 0 <= j and j < w and f[i][j] != '#'; }

bool solve()
{
        for (int i = 0; i < 4; i++) dd[i].clear();
        dd[0].push_back(0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
                sum += (s[i]=='R'? 1: -1);
                dd[(sum%4+4)%4].push_back(i+1);
        }
        int si = -1, sj = -1;
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        if(f[i][j] == 'S') {
                                si = i;
                                sj = j;
                                break;
                        }
                }
                if(si >= 0) break;
        }
        memset(dist,-1,sizeof(dist));
        priority_queue<node> q;
        q.push(node(si,sj,0,0));
        while(!q.empty()) {
                node v = q.top(); q.pop();
                if(~dist[v.i][v.j][v.dir]) continue;
                dist[v.i][v.j][v.dir] = v.cst;
                if(f[v.i][v.j] == 'G') return 1;
                for (int d = 0; d < 4; d++) {
                        auto it = lower_bound(begin(dd[d]),end(dd[d]), v.cst);
                        if(it == end(dd[d])) continue;
                        int ni = v.i+di[d], nj = v.j+dj[d];
                        if(ok(ni,nj)) q.push(node(ni,nj,d,*it));
                }
        }
        return 0;
}

bool input()
{
        scanf("%d%d%d", &h, &w, &n);
        if(!h and !w and !n) return 0;
        scanf("%s", s);
        for (int i = 0; i < h; i++) scanf("%s", f[i]);
        return 1;
}

int main()
{
        while(input()) puts(solve()? "Yes": "No");
        return 0;
}
