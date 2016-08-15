#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int N = 1e7;
vector<int> primes;
bool np[N];

void gen_p() {
    for(int i = 2; i*i < N; i++) {
        if(np[i]) continue;
        primes.push_back(i);
        reps(j,i+i,N,i) np[i] = 1;
    }
}

i64 count(int n) {
    i64 ret = 1;
    for (auto &p: primes) {
        if(p*p > n) break;
        int c = 0;
        while(n%p == 0) {
            c++;
            n /= p;
        }
        ret *= c+1;
    }
    if(n > 1) ret *= 2;
    return ret;
}

void solve() {
    gen_p();
    int pv = 1, ans = 0;
    repi(n,2,N+1) {
        int c = count(n);
        if(pv == c) ans++;
        pv = c;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
