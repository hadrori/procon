#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, a[128], b[128], c[128];

int solve() {
    rep(i,n) c[b[i]] += a[i];
    return c[0] == *max_element(c,c+101);
}

void input() {
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    puts(solve()? "YES": "NO");
    return 0;
}
