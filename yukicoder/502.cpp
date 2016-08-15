#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, c[128];

int solve() {
    int m = accumulate(c,c+n,0), sum = 0;
    rep(i,n) if(c[i] <= m/10) sum += 30;
    return sum;
}

void input() {
    scanf("%d", &n);
    rep(i,n) scanf("%d", c+i);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
