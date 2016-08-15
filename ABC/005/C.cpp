#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int t, n, m, a[128], b[128];

bool solve() {
    rep(i,m) {
        int f = 0;
        repi(j,max(0,b[i]-t),b[i]+1) if(a[j]) {
            f = 1;
            a[j]--;
            break;
        }
        if(!f) return 0;
    }
    return 1;
}

void input() {
    cin >> t >> n;
    int x;
    rep(i,n) { cin >> x; a[x]++; }
    cin >> m;
    rep(i,m) cin >> b[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << (solve()? "yes": "no") << endl;
    return 0;
}
