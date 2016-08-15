#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)
const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

struct sale { int d, s, e; };
int n, h, w, f[32][32], pi, pj;
bool done[21][21][1<<10][101];
vector<sale> ts[16];

inline bool in(int i, int j) { return i >= 0 and i < h and j >= 0 and j < w; }

int solve() {
    memset(done,0,sizeof(done));
    queue<tuple<int,int,int,int,int>> q;
    q.push(make_tuple(pi,pj,0,0,0));
    int ans = 0;
    while(!q.empty()) {
        int i, j, s, t, v;
        tie(i,j,s,t,v) = q.front(); q.pop();
        if(t > 100) continue;
        if(done[i][j][s][t]) continue;
        done[i][j][s][t] = 1;
        ans = max(ans, v);
        rep(d,4) {
            const int ni = i+di[d], nj = j+dj[d];
            if(!in(ni,nj)) continue;
            if(~f[ni][nj]) {
                const int g = f[ni][nj];
                if(s>>g&1) continue;
                int mx = 0;
                for(auto &e: ts[g]) if(e.s <= t and t < e.e) mx = max(mx, e.d);
                if(mx) q.push(make_tuple(i,j,1<<g|s,t,v+mx));
            }
            else q.push(make_tuple(ni,nj,s,t+1,v));
        }
    }
    return ans;
}

bool input() {
    cin >> w >> h;
    if(!w and !h) return 0;
    rep(i,10) ts[i].clear();
    rep(i,h) rep(j,w) {
        char c; cin >> c;
        if(c == '.' or c == 'P') f[i][j] = -1;
        else f[i][j] = c-'0';
        if(c == 'P') pi = i, pj = j;
    }
    cin >> n;
    rep(i,n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ts[a].push_back((sale){b,c,d});
    }
    return 1;
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
