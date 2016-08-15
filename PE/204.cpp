#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int N = 100, M = 1e9;
bool isnp[N];
vector<int> ps;

void primes() {
    repi(i,2,N) if(!isnp[i]) {
        ps.push_back(i);
        for(int j = i+i; j < N; j+=i) isnp[j] = 1;
    }
}

int dfs(i64 num, int last) {
    if(num > M) return 0;
    int ret = 1;
    repi(i,last,ps.size()) ret += dfs(num * ps[i], i);
    return ret;
}

void solve() {
    primes();
    cout << dfs(1,0) << endl;
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
