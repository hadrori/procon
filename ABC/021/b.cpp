#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, a, b, k, p[128], q[128];

bool solve() {
    rep(i,k) {
        if(q[p[i]]) return 0;
        q[p[i]] = 1;
    }
    return 1;
}

void input() {
    cin >> n >> a >> b >> k;
    p[0] = a;
    p[k+1] = b;
    rep(i,k) cin >> p[i+1];
    k += 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << (solve()?"YES":"NO") << endl;
    return 0;
}
