#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int n, m, w[512], l[512], r[512], p[512], dp[512], ans[512];

void solve()
{
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    rep(i,n) repi(j,l[i],r[i]+1) rep(k,393-j+1)
        if(~dp[k]) dp[k+j] = max(dp[k+j], dp[k]+p[i]);
    bool f = 1;
    rep(i,m) if(dp[w[i]] < 0) {
        f = 0;
        break;
    }
    if(!f) puts("-1");
    else rep(i,m) printf("%d\n", dp[w[i]]);
}

void input()
{
    scanf("%d", &n);
    rep(i,n) scanf("%d%d%d", l+i, r+i, p+i);
    scanf("%d", &m);
    rep(i,m) scanf("%d", w+i);
}

int main()
{
    input();
    solve();
    return 0;
}
