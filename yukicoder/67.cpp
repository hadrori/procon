#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, k, a[10];


int solve() {
    sort(a,a+n);
    return a[n-1]-a[0];
}

void input() {
    scanf("%d%d", &n, &k);
    rep(i,n) scanf("%d", a+i);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
