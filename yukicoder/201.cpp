#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int w, h;
char c[2];

void solve() {
    if(c[0] == 'W') c[1] = 'B';
    else c[1] = 'W';
    rep(i,h) {
        rep(j,w) cout << c[j%2];
        cout << endl;
        swap(c[0], c[1]);
    }
}

void input() {
    cin >> w >> h >> c[0];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
