#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
const int mod = 1e9+9;
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
typedef pair<int,int> pii;
typedef int64_t i64;

inline void add(int &x, int y) { x = (x+y)%mod; }
inline void sub(int &x, int y) { x = (x-y+mod)%mod; }
inline int mul(int x, int y) { return 1LL*x*y%mod; }

int fact[1<<20];
i64 extgcd(i64 a, i64 b, i64 &x, i64 &y) {
    i64 g = a; x = 1, y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
int inv(int a) { i64 x, y; extgcd(a,mod,x,y); return (x%mod+mod)%mod; }
int binom(int a, int b) { return mul(fact[a], inv(mul(fact[b],fact[a-b]))); }

const int M = 60;
int n, m, dp[M+10][M+10], dp1[M+10][M+10], dp2[M+10][M+10];
vector<pii> vs, tvs;

bool in(int i, int l, int r) {
    return vs[l].first <= vs[i].first and vs[i].first <= vs[r].first and
        vs[l].second <= vs[i].second and vs[i].second <= vs[r].second;
}

int rec(int l, int r) {
    if(~dp[l][r]) return dp[l][r];
    int lx = vs[l].first, ly = vs[l].second, rx = vs[r].first, ry = vs[r].second;
    dp[l][r] = binom(rx-lx+ry-ly, rx-lx);
    rep(i,m) if(i != l and i != r and in(i,l,r))
        sub(dp[l][r], mul(rec(l,i), rec(i,r)));
    return dp[l][r];
}

int bfs(int s, int t, int l, int r, int dp[M+10][M+10], int b) {
    bool done[M+10][M+10]; memset(done, 0, sizeof(done));
    memset(dp, 0, sizeof(int)*(M+10)*(M+10));
    dp[s-b][s-b] = 1;
    queue<pii> q; q.emplace(s,s);
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(done[x-b][y-b]) continue;
        done[x-b][y-b] = 1;
        if(x == t and y == t) return dp[x-b][y-b];
        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if(nx < l or ny < l or nx >= r or ny >= r) continue;
            if(done[nx-b][ny-b]) continue;
            bool ok = 1;
            rep(i,m) if(tvs[i].first == x and tvs[i].second == y) ok = 0;
            if(!ok) continue;
            add(dp[nx-b][ny-b], dp[x-b][y-b]);
            q.emplace(nx,ny);                
        }
    }
    return 0;
}

void calc(int s, int t, int l, int r, vector<pii> &c, int b) {
    int done[M+10][M+10]; memset(done, 0, sizeof(done));
    queue<tuple<int,int,int>> q;
    q.emplace(0,s,s);
    int mc = 1000000000, d, x, y;
    while(!q.empty()) {
        tie(d,x,y) = q.front(); q.pop();
        if(done[x-b][y-b]) continue;
        done[x-b][y-b] = 1;
        if(x == t or y == t) {
            if(d <= mc) {
                mc = d;
                c.emplace_back(x,y);
            }
        }
        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if(nx < l or ny < l or nx >= r or ny >= r) continue;
            bool ok = 1;
            rep(i,m) if(tvs[i].first == x and tvs[i].second == y) ok = 0;
            if(!ok) continue;
            int nd = d;
            if(abs(s-nx)+abs(s-ny) < abs(s-x)+abs(s-y)) nd++;
            q.emplace(nd,nx,ny);
        }
    }
}

void set_vs(pii &x, pii &y) {
    vs.clear();
    vs.push_back(x);
    vs.insert(end(vs),begin(tvs),end(tvs));
    vs.push_back(y);
}

int solve() {
    if(n <= 200) return bfs(0,n-1,0,n,dp,0);
    vector<pii> lc, rc;
    bfs(0,-1,0,M,dp1,0);
    bfs(n-1,-1,n-M,n,dp2,n-M);
    calc(0,M-1,0,M,lc,0);
    calc(n-1,n-M,n-M,n,rc,n-M);
    int ans = 0;
    m += 2;
    sort(begin(tvs),end(tvs));
    rep(i,lc.size()) {
        rep(j,rc.size()) {
            set_vs(lc[i],rc[j]);
            memset(dp, -1, sizeof(dp));
            add(ans, mul(mul(dp1[lc[i].first][lc[i].second], dp2[rc[j].first-(n-M)][rc[j].second-(n-M)]),rec(0,m-1)));
        }
    }
    return ans;
}

void input() {
    cin >> n >> m;
    int x, y;
    rep(i,m) {
        cin >> x >> y;
        tvs.push_back(pii(x-1,y-1));
    }
}

int main() {
    fact[0] = 1;
    repi(i,1,1<<20) fact[i] = mul(fact[i-1],i);
    input();
    cout << solve() << endl;
    return 0;
}
