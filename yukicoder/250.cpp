#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int q, d, x, t;

int comb(int n, int k) {
    long long f = 1;
    while(k) {
    }
}

void solve() {
    while(q--) {
        scanf("%d%d%d", &d, &x, &t);
        puts(comb(x+1,d-1)? "AC": "ZETUBOU");
    }
}

void input() {
    scanf("%d", &q);
}

int main() {
    input();
    solve();
    return 0;
}
