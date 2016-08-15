#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, k, t[8][8];

bool dfs(int i, int val) {
    if(i == n) return !val;
    rep(j,k) if(dfs(i+1,val^t[i][j])) return 1;
    return 0;
}

bool solve() {
    return dfs(0,0);
}

void input() {
    cin >> n >> k;
    rep(i,n) rep(j,k) cin >> t[i][j];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << (solve()? "Found": "Nothing") << endl;
    return 0;
}
