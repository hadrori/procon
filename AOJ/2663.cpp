#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

typedef long long i64;
int n, m, a[300010], b[300010];
i64 c[300010], sum[300010];

void solve() {
    sort(a,a+n);
    rep(i,n) sum[i+1] = sum[i]+a[i];
    rep(i,m) {
        if(sum[upper_bound(a,a+n,b[i])-a] >= c[i]) puts("Yes");
        else puts("No");
    }
}

void input() {
    cin >> n;
    rep(i,n) cin >> a[i];
    cin >> m;
    rep(i,m) cin >> b[i];
    rep(i,m) cin >> c[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
