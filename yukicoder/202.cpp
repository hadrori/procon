#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, a[100010], cnt[8];

int solve() {
    rep(i,n) cnt[a[i]]++;
    int x = 0, y = 0;
    rep(i,7) {
        if(x <= cnt[i]) {
            x = cnt[i];
            y = i;
        }
    }
    return y;
}

void input() {
    cin >> n;
    rep(i,n) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
