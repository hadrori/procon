#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

string s[128];
int w, h, f[128][128], dd[8][8], dist[128][128], x[8], y[8];
inline bool in(int i, int j) { return i >= 0 and i < h and j >= 0 and j < w; }
inline void chmin(int &x, int y) { x = x<0? y: min(x,y); }

void dijkstra(int si, int sj) {
    memset(dist,-1,sizeof(dist));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
    q.push(make_tuple(0,si,sj));
    while(!q.empty()) {
        int d, i, j;
        tie(d,i,j) = q.top(); q.pop();
        if(~dist[i][j]) continue;
        dist[i][j] = d;
        rep(k,4) {
            int ni = i+di[k], nj = j+dj[k];
            if(in(ni,nj) and ~f[ni][nj]) q.push(make_tuple(d+f[i][j],ni,nj));
        }
    }
}

int dp[1<<8][8];

int solve() {
    rep(i,h) rep(j,w) f[i][j] = 1;
    int m = 1;
    rep(i,h) rep(j,w) {
        if(s[i][j] == 'M') {
            x[m] = j;
            y[m] = i;
            m++;
        }
        else if(s[i][j] == 'S')  {
            x[0] = j;
            y[0] = i;
        }
        else if(s[i][j] == '#') {
            f[i][j] = -1;
            repi(ni,i-2,i+3) repi(nj,j-2,j+3) if(in(ni,nj) and s[ni][nj] != '#')
                f[ni][nj] = max(f[ni][nj], 4-max(abs(ni-i), abs(nj-j)));
        }
    }
    // rep(i,h) { rep(j,w) cerr << f[i][j] << ' '; cerr << endl; }
    rep(i,h) rep(j,w) if(s[i][j] == 'G') { x[m] = j; y[m] = i; m++; }
    memset(dd,-1,sizeof(dd));
    rep(i,m) {
        dijkstra(y[i], x[i]);
        rep(j,m)  dd[i][j] = dist[y[j]][x[j]];
    }
    // rep(i,m) { rep(j,m) cerr << dd[i][j] << ' '; cerr << endl; }
    memset(dp,-1,sizeof(dp));
    dp[1][0] = 0;
    rep(i,1<<m) rep(j,m) if(~dp[i][j]) {
        rep(k,m) if(~dd[j][k] and !(i>>k&1)) chmin(dp[1<<k|i][k], dp[i][j]+dd[j][k]);
    }
    return dp[(1<<m)-1][m-1];
}

void input() {
    cin >> w >> h;
    rep(i,h) cin >> s[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
