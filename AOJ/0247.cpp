#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int di[] = {1,0,-1,0}, dj[] = {0,1,0,-1};

string f[16];
int w, h, id[16][16], lim[256];

inline bool in(int i, int j) { return 0 <= i and i < h and 0 <= j and j < w; }

int bfs(int i, int j, int idx) {
    queue<tuple<int,int>> q;
    q.push(make_tuple(i,j));
    int cnt = 0;
    while(!q.empty()) {
        tie(i,j) = q.front(); q.pop();
        if(~id[i][j]) continue;
        id[i][j] = idx;
        cnt++;
        rep(d,4) {
            int ni = i+di[d], nj = j+dj[d];
            if(in(ni,nj) and f[ni][nj] == 'X') q.push(make_tuple(ni,nj));
        }
    }
    return cnt;
}

int ans, visited[16][16], si, sj, gi, gj;

void dfs(int i, int j, int e) {
    if(abs(i-gi)+abs(j-gj)+e >= ans) return;
    if(i == gi and j == gj) { ans = e; return; }
    int c = 0;
    rep(d,4) {
        int ni = i+di[d], nj = j+dj[d];
        if(in(ni,nj) and visited[ni][nj]) c++;
    }
    if(c >= 2) return;
    visited[i][j] = 1;
    rep(d,4) {
        int ni = i+di[d], nj = j+dj[d];
        if(in(ni,nj) and !visited[ni][nj] and f[ni][nj] != '#') {
            if(f[ni][nj] == 'X') {
                if(lim[id[ni][nj]]) {
                    lim[id[ni][nj]]--;
                    dfs(ni,nj,e+1);
                    lim[id[ni][nj]]++;
                }
            }
            else dfs(ni,nj,e+1);
        }
    }
    visited[i][j] = 0;
}

int solve() {
    int idx = 0;
    memset(id,-1,sizeof(id));
    memset(lim,0,sizeof(lim));
    rep(i,h) rep(j,w) {
        if(id[i][j] < 0 and f[i][j] == 'X') {
            lim[idx] = bfs(i,j,idx)/2;
            idx++;
        }
        else if(f[i][j] == 'S') si = i, sj = j;
        else if(f[i][j] == 'G') gi = i, gj = j;
    }
    memset(visited,0,sizeof(visited));
    ans = h*w;
    dfs(si,sj,0);
    return ans;
}

bool input() {
    cin >> w >> h;
    rep(i,h) cin >> f[i];
    return w or h;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) {
        cout << solve() << endl;
    }
    return 0;
}
