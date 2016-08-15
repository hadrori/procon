#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int M = 1e4, N = M*M;
inline i64 sq(i64 x) { return x*x; }

bool pal(int x) {
    string s = to_string(x);
    rep(i,s.size()/2) if(s[i] != s[s.size()-i-1]) return 0;
    return 1;
}

i64 sum(i64 n) { return n*(n+1)*(2*n+1)/6; }
i64 sum(i64 l, i64 r) { return sum(r-1) - sum(l-1); }

void solve() {
    set<int> ss;
    repi(l,1,M) {
        repi(r,l+2,M+1) {
            i64 s = sum(l,r);
            if(s >= N) break;
            if(pal(s)) ss.insert(s);
        }
    }
    cout << accumulate(begin(ss),end(ss), 0LL) << endl;
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
