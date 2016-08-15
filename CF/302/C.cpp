#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, m, a[256];

int solve() {
    sort(a,a+m);
    while(a[0] < 0 and a[n-1] <= 0) {
        rep(i,n) a[i] *= -1;
        sort(a,a+m);
    }
    if(a[0] < 0) {
        int nc = 0;
        rep(i,n) if(a[i] < 0) a[i] *= -1, nc++;
        int mc = n-nc;
        while(nc >= 2) nc -= 2;
        while(mc >= 2) mc -= 2;
        nc = min(nc, mc);
        sort(a,a+m);
        if(nc) a[0] *= -1;
    }
    return accumulate(a,a+m,0);
}

void input() {
    cin >> n;
    m = 2*n-1;
    rep(i,m) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
