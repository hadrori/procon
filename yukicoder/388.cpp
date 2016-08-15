#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

inline int sq(int x) { return x*x; }
int x, y, r;

bool ok(int m) {
    const int cx = (m+x-y)*5, cy = -cx+m*10;
    return sq(10*r) < sq(cx-10*x)+sq(cy-10*y);
}

int solve() {
    if(x < 0) x *= -1;
    if(y < 0) y *= -1;
    int lb = x+y+r, ub = 1024, m;
    while(ub-lb > 1) {
        m = (lb+ub)/2;
        if(ok(m)) ub = m;
        else lb = m;
    }
    return ub;
}

void input() {
    scanf("%d%d%d", &x, &y, &r);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
