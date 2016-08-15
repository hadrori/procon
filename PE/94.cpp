#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int N = 1e9;

inline i64 sq(i64 x) { return x*x; }

bool check(i64 x, i64 y) { // 1/4 * y * sqrt(4*x*x - y*y)
    if(sq(y)%4) return 0;
    i64 p = x*x-y*y/4, q = sqrt(p);
    return sq(q) == p or sq(q-1) == p or sq(q+1) == p;
}

void solve() {
    i64 ans = 0;
    repi(i,5,N+1) {
        if((i-1)%3 == 0 and check((i+1)/3,(i+1)/3+1)) ans += i;
        else if((i+1)%3 == 0 and check((i+1)/3,(i+1)/3-1)) ans += i;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
