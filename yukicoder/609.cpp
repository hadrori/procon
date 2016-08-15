#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n;
string s, t;

int solve() {
    int a = 0;
    rep(i,n) a += s[i] != t[i];
    return a;
}

void input() {
    cin >> n >> s >> t;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
