#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define int long long


int n, a, b, m[1024];

int solve() {
    int k = 0, f = 0;
    rep(i,n) {
        k = max(k, m[i]);
        f |= 1<<(m[i]%2);
    }
    if(f == 3) return -1;
    int ans = 0;
    rep(i,n) ans += (k-m[i])/2;
    return ans;
}

void input() {
    cin >> n;
    rep(i,n) {
        cin >> a >> b;
        m[i] = a+4*b;
    }
}

signed main() {
    input();
    cout << solve() << endl;
    return 0;
}
