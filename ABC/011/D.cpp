#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, d, x, y;

long double solve() {
    x = abs(x); y = abs(y);
    if(x%d or y%d) return 0;
    x /= d; y /= d;
    long double ans = 0;
    for(int i = x; i <= n; i+= 2) {
        const int j = n-i, v = (i-x)/2, w = (j-y)/2;
        if(j < y or (j-y)%2) continue;
        long double val = -2*n;
        repi(k,1,n+1) {
            val += log2(k);
            if(v >= k) val -= log2(k);
            if(i-v >= k) val -= log2(k);
            if(w >= k) val -= log2(k);
            if(j-w >= k) val -= log2(k);
        }
        ans += pow(2.0,val);
    }
    return ans;
}

void input() {
    cin >> n >> d >> x >> y;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
