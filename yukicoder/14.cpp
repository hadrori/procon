#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int l, n, w[10010], dp[10010];

int solve() {
    rep(i,n) for (int j = l; j >= w[i]; j--) dp[j] = max(dp[j],dp[j-w[i]]+1);
    return dp[l];
}

void input() {
    scanf("%d%d", &l, &n);
    rep(i,n) scanf("%d", w+i);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
