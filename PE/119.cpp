#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const i64 N = 1e15, M = sqrt(N);
vector<i64> vs;

void check(i64 x, int v) {
    i64 s = 0, t = x;
    while(x) { s += x%10; x/=10; }
    if(v == s) vs.push_back(t);
}

void solve() {
    repi(i,2,1e4) {
        i64 x = i;
        while(x < N) {
            if(x >= 10) check(x, i);
            x *= i;
        }
    }
    sort(begin(vs),end(vs));
    cout << "size : " << vs.size() << endl;;
    rep(i,10) cout << vs[i] << ' '; cout << endl;
    cout << vs[29] << endl;
}

int main() {
    solve();
    return 0;
}
