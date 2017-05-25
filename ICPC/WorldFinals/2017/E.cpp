#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, t, d[1024], s[1024];

bool big(double x) {
    double sum = 0;
    rep(i,n) {
        if(s[i]+x < 1e-9) return false;
        sum += 1.0*d[i] / (1.0*s[i]+x);
    }
    return sum < 1.0*t;
}

double solve() {
    double lb = -1e9, ub = 1e9, mid;
    rep(_,100) {
        mid = (lb+ub)/2;
        if(big(mid)) ub = mid;
        else lb = mid;
    }
    return lb;
}

void input() {
    cin >> n >> t;
    rep(i,n) cin >> d[i] >> s[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
