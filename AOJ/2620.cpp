#include <bits/stdc++.h>
using namespace std;
const string dir = "RDLU";
const int dy[] = {0,1,0,-1}, dx[] = {1,0,-1,0};

struct node
{
        int x, y, d;
        node(int x, int y, int d) : x(x), y(y), d(d){}
        bool operator<(const node &v) const { return d > v.d;}
};

int w, h, n, sx, sy, tx, ty;
int cnt[512][512][4], done[512][512];

inline bool in(int x, int y) { return 0<=x and x<w and 0<=y and y<h;}

int step(int x, int y, int d)
{
        if(d == 0) return y? cnt[x][y-1][1]+cnt[x][y][3]: 0;
        if(d == 1) return x? cnt[x-1][y][0]+cnt[x][y][2]: 0;
        if(d == 2) return y? cnt[x-1][y-1][1]+cnt[x-1][y][3]: 0;
        if(d == 3) return x? cnt[x-1][y-1][0]+cnt[x][y-1][2]: 0;
        return -1;
}

int solve()
{
        w++; h++;
        priority_queue<node> q;
        q.push(node(sx,sy,0));
        while(!q.empty()) {
                int x = q.top().x, y = q.top().y, d = q.top().d;
                q.pop();
                if(done[x][y]) continue;
                done[x][y] = 1;
                if(x == tx and y == ty) return d;
                for (int i = 0; i < 4; i++) {
                        int nx = x+dx[i], ny = y+dy[i];
                        if(!in(nx,ny)) continue;
                        q.push(node(nx,ny,d+step(x,y,i)));
                }
        }
        return -1;
}

void input()
{
        cin >> w >> h >> n >> sx >> sy >> tx >> ty;
        for (int i = 0; i < n; i++) {
                int x, y, t; cin >> x >> y >> t;
                string s; cin >> s;
                while(t--) {
                        for(auto &c: s) {
                                const int d = dir.find(c);
                                cnt[x][y][d]++;
                                x += dx[d];
                                y += dy[d];
                                if(!in(x,y)) {
                                        x -= dx[d];
                                        y -= dy[d];
                                        cnt[x][y][d]--;
                                }
                        }
                }
        }
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
