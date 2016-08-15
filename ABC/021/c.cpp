#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int mod = 1e9+7;
inline void add(int &x, int y) { x = (x + y) % mod; }

int n, s, t, m, f[128], dist[128];
vector<int> G[128];

void solve() {
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    f[s] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for (int &w: G[v]) {
            if(dist[w] < 0) {
                dist[w] = dist[v]+1;
                q.push(w);
            }
            if(dist[w] == dist[v]+1) add(f[w],f[v]);
        }
    }
    cout << f[t] << endl;
}

void input() {
    cin >> n >> s >> t >> m; s--; t--;
    rep(i,m) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
