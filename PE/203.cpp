#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const i64 N = 51, K = 2e7;
i64 comb[N+1][N+1];
bool isnp[K];
vector<i64> ps;

void primes() {
    const int K = 2e7;
    isnp[0] = isnp[1] = 1;
    repi(i,2,K) if(!isnp[i]) {
        ps.push_back(1LL*i*i);
        if(i*i > K) continue;
        for(int j = i+i; j < K; j += i) isnp[j] = 1;
    }
}

void solve() {
    primes();
    comb[0][0] = 1;
    set<i64> cs;
    repi(i,1,N) {
        comb[i][0] = 1;
        rep(j,i+1) comb[i][j+1] = comb[i-1][j+1] + comb[i-1][j];
        rep(j,i/2+1) {
            bool ok = 1;
            for(auto &p: ps) {
                if(!ok or p > comb[i][j]) break;
                ok &= comb[i][j] % p > 0;
            }
            if(ok) cs.insert(comb[i][j]);
        }
    }
    cout << accumulate(begin(cs), end(cs), 0LL) << endl;
}

void input() {
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
