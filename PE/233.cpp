#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int K = 53;
const int M = 200000;

vector<int> ps;
bool isnp[M+1];

void gen_p() {
    repi(i,2,M) if(!isnp[M+1]) {
        ps.push_back(i);
        reps(j,i+i,M,i) isnp[j] = 1;
    }
}

void solve() {
    gen_p();
    cerr << ps.size() << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
