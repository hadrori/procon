#include <bits/stdc++.h>
using namespace std;

const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

struct node
{
        int i, j;
        set<pair<int,int>> c, p;
        node(){}
        bool operator<(const node &n) const {
                if(i != n.i) return i < n.i;
                if(j != n.j) return j < n.j;
                if(c != n.c) return c < n.c;
                return p < n.p;
        }
};


int h, w, ti, tj;
char f[10][10];
map<node,int> done;

struct comp { bool operator()(const node &u, const node &v) { return done[u] > done[v]; } };

int solve()
{
        done.clear();
        node v;
        for (int i = 1; i < h-1; i++) {
                for (int j = 1; j < w-1; j++) {
                        if(f[i][j] == '@') {
                                v.i = i;
                                v.j = j;
                                f[i][j] = '.';
                        }
                        else if(f[i][j] == 'c') {
                                v.c.insert(make_pair(i,j));
                                f[i][j] = '.';
                        }
                        else if(f[i][j] == 'w') {
                                v.p.insert(make_pair(i,j));
                                f[i][j] = '.';
                        }
                        else if(f[i][j] == 'E') {
                                ti = i;
                                tj = j;
                                f[i][j] = '.';
                        }
                }
        }

        priority_queue<node,vector<node>,comp> q;
        done[v] = 0;
        q.push(v);
        while(!q.empty()) {
                v = q.top(); q.pop();
                int dist = done[v];
                if(v.i == ti and v.j == tj) return dist;
                char g[10][10];
                memcpy(g,f,sizeof(f));
                for(auto &e: v.c) f[e.first][e.second] = 'c';
                for(auto &e: v.p) f[e.first][e.second] = 'w';

                node nv = v;
                for (int d = 0; d < 4; d++) {
                        const int ni = v.i+di[d], nj = v.j+dj[d];
                        if(f[ni][nj] == '.') {
                                nv.i = ni;
                                nv.j = nj;
                                if(!done.count(nv)) {
                                        done[nv] = dist+1;
                                        q.push(nv);
                                }
                        }
                }
                nv = v;
                for (int d = 0; d < 4; d++) {
                        const int ni = v.i+di[d], nj = v.j+dj[d];
                        if(f[ni][nj] == 'c') {
                                int nni = ni+di[d], nnj = nj+dj[d];
                                while(f[nni][nnj] == '.') {
                                        nni += di[d];
                                        nnj += dj[d];
                                }
                                nv = v;
                                nv.c.erase(make_pair(ni,nj));
                                if(f[nni][nnj] == 'w') nv.p.erase(make_pair(nni,nnj));
                                else nv.c.insert(make_pair(nni-di[d],nnj-dj[d]));
                                
                                if(!done.count(nv) or done[nv] > dist) {
                                        done[nv] = dist;
                                        q.push(nv);
                                }
                        }
                }
                memcpy(f,g,sizeof(f));
        }
        return -1;
}

bool input()
{
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) scanf("%s", f[i]);
        return h or w;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
