#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const i64 N = 1e10, M =1e6;

bool np[M];

void test(i64 p, i64 n) {
    cerr << "prime : " << p << endl;
    i64 x = 1, y = 1;
    rep(i,n) x = (x*(p-1))%(p*p);
    rep(i,n) y = (y*(p+1))%(p*p);
    cerr << p-1 << "^" << n << " + " << p+1 << "^" << n << " = " << (x+y)%(p*p) << " (mod " << p*p << ")" << endl;
    cerr << p-1 << "^" << n << " + " << p+1 << "^" << n << " = " << 2LL*n*p << " (mod " << p*p << ")" << endl;
}

int solve() {
    int n = 0;
    repi(p,2,M) if(!np[p]) {
        n++;
        reps(i,p+p,M,p) np[i] = 1;
        i64 x = n%2 ? 2LL*n*p : 2;
        if(x > N) {
            test(p, n);
            return n;
        }
    }
    return -1;
}

int main() {
    cout << solve() << endl;
    return 0;
}
