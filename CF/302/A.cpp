#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, m, a[200010], cnt[2];

void solve() {
    rep(i,n) cnt[a[i]>0]++;
    rep(i,m) {
        int l, r; cin >> l >> r; l--;
        int k = (r-l)/2;
        if((r-l)%2) cout << 0 << endl;
        else cout << (cnt[0] >= k and cnt[1] >= k) << endl;
    }
}

void input() {
    cin >> n >> m;
    rep(i,n) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
