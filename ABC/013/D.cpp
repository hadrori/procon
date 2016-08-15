#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, m, d, id[100010], a[100010], b[100010], pos[100010];
vector<vector<int>> scc;

void solve() {
    memset(id,-1,sizeof(id));
    rep(i,n) b[a[i]] = i;
    rep(i,n) if(id[i] < 0) {
        int v = i;
        scc.push_back(vector<int>());
        while(id[v] < 0) {
            id[v] = scc.size()-1;
            pos[v] = scc.back().size();
            scc.back().push_back(v);
            v = b[v];
        }
    }
    rep(i,n) {
        int k = scc[id[i]].size();
        cout << scc[id[i]][(d%k+pos[i])%k]+1 << endl;
    }
}

void input() {
    cin >> n >> m >> d;
    rep(i,n) a[i] = i;
    rep(i,m) {
        int x; cin >> x;
        swap(a[x-1], a[x]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
