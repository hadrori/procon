#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int h, w;
string f[128];

void solve() {
    rep(i,h) {
        int c = -1;
        rep(j,w) {
            if(f[i][j] == 'c') c = 0;
            else if(~c) c++;
            cout << c << (j==w-1? '\n': ' ');
        }
    }
}

void input() {
    cin >> h >> w;
    rep(i,h) cin >> f[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
