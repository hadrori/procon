#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

string s, t;

int solve() {
    s += t;
    int ans = 0, a = 0;
    rep(i,14) {
        if(s[i] == 'x') a = 0;
        else a++;
        ans = max(ans, a);
    }
    return ans;
}

void input() {
    cin >> s >> t;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
