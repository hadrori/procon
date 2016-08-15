#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, m;
map<string,int> cnt;

void solve() {
    cin >> n;
    string s, ans;
    rep(i,n) {
        cin >> s;
        cnt[s]++;
        if(m < cnt[s]) {
            m = cnt[s];
            ans = s;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
