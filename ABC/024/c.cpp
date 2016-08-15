#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, d, k, m, l[10010], r[100010], s[110], t[110], ans[128];

void solve() {
    rep(i,d) {
        rep(j,k) if(!ans[j]) {
            if(l[i] <= s[j] and s[j] <= r[i] and l[i] <= t[j] and t[j] <= r[i]) ans[j] = i+1;
            else if(l[i] <= s[j] and s[j] <= r[i]) {
                if(s[j] < t[j]) s[j] = r[i];
                else s[j] = l[i];
            }
        }
    }
    rep(i,k) cout << ans[i] << endl;
}

void input() {
    cin >> n >> d >> k;
    rep(i,d) cin >> l[i] >> r[i];
    rep(i,k) cin >> s[i] >> t[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
