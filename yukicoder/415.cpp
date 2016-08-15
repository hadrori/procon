#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, m;

int solve() {
    return m*(1<<(n-3));
}

void input() {
    cin >> n >> m;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
