#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, c[100000];

vector<int> lis(const vector<int> &s) {
    const int n = s.size(), inf = 1e9;
    vector<int> id(n), dp(n,inf);
    for (int i = 0; i < n; i++) {
        id[i] = lower_bound(begin(dp), end(dp), s[i]) - begin(dp);
        dp[id[i]] = s[i];
    }
    int m = *max_element(begin(id), end(id));
    vector<int> ret(m+1);
    for (int i = n-1; i >= 0; i--)
        if(id[i] == m) ret[m--] = s[i];
    return ret;
}
void solve() {
    cout << n-lis(vector<int>(begin(c), begin(c)+n)).size() << endl;
}

void input() {
    cin >> n;
    rep(i,n) cin >> c[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
