#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
using pii = pair<int,int>;

const int N = 40;

int g[N][N], used[N];

void solve() {
    int sum = 0;
    rep(i,N) rep(j,N) sum += g[i][j];
    sum /= 2;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(pii(0,0));
    while(!q.empty()) {
        int c = q.top().first, v = q.top().second; q.pop();
        if(used[v]) continue;
        used[v] = 1;
        sum -= c;
        rep(i,N) if(g[v][i]) q.push(pii(g[v][i], i));
    }
    cout << sum << endl;
}

void input() {
    rep(i,N) rep(j,N) cin >> g[i][j];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
