#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, s[1024];

void solve() {
    rep(i,n) {
        if(6*s[i] >= 3000000) {
            puts("YES");
            rep(j,6) printf("%d\n", i+1);
            return;
        }
    }
    puts("NO");
}

void input() {
    scanf("%d", &n);
    int g, d;
    rep(i,n) {
        scanf("%d%d", &g, &d);
        s[i] = g-30000*d;
    }
}

int main() {
    input();
    solve();
    return 0;
}
