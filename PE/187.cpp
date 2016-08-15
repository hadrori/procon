#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int N = 1e8;

int cnt[N];

void solve() {
    int ans = 0;
    repi(i,2,N) {
        if(cnt[i]) {
            if(cnt[i] == 2) ans++;
            continue;
        }
        for(i64 s = 1; s < N; s *= i)
            for(i64 j = s*i; j < N; j += s*i)
                cnt[j]++;
    }
    repi(i,2,30) cerr << cnt[i] << ' '; cerr << endl;
    cout << ans << endl;
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
