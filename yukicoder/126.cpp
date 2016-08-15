#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int x = 60*24;
int n, lh[32], lm[32], rh[32], rm[32];

int solve() {
    int ans = 0;
    rep(i,n) ans += (rh[i]-lh[i]+24)%24*60+rm[i]-lm[i];
    return ans;
}

void input() {
    scanf("%d", &n);
    rep(i,n) scanf("%d:%d %d:%d", lh+i, lm+i, rh+i, rm+i);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
