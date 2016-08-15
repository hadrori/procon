#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n, a[128];

int solve() {
    int sum = accumulate(a,a+n,0), m = sum / n;
    if(sum % n) return -1;
    int ans = n, l = 0, r = 0;
    sum = 0;
    while(r < n) {
        sum += a[r++];
        if(m*(r-l) == sum) {
            ans--;
            l = r;
            sum = 0;
        }
    }
    return ans;
}

void input() {
    cin >> n;
    rep(i,n) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
