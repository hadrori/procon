#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

string s;
int n;

void solve() {
    while(n--) {
        int l, r; cin >> l >> r; l--;
        reverse(begin(s)+l,begin(s)+r);
    }
    cout << s << endl;
}

void input() {
    cin >> s >> n;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
