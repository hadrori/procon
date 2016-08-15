#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, m, a[100010], b[100010];

void solve() {
    int i = 0;
    rep(j,m) {
        while(a[i+1] < b[j]) i++;
        cout << i+1 << endl;
    }
}

void input() {
    scanf("%d%d", &n, &m);
    int c, t;
    rep(i,n) {
        scanf("%d%d", &c, &t);
        a[i+1] = a[i]+c*t;
    }
    rep(i,m) scanf("%d", b+i);
}


int main() {
    input();
    solve();
    return 0;
}
