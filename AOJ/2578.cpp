#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

inline void chmax(int &x, int y) { x=max(x,y); }
int t, n, u, s, o, d, e[128], c[128], h[128], a[128];
int dp1[128][128], dp2[10010], dp3[128][128];
/*
  dp1[i][j] := max cal in energy i, training j
  dp2[i] := max happiness in cal i
  dp3[i][j] := max happiness in energy j, day i
*/

int solve()
{
    memset(dp1,-1,sizeof(dp1));
    dp1[0][0] = 0;
    rep(i,t) for(int j = u-1; j >= 0; j--) rep(k,s-e[i]+1) if(~dp1[j][k]) chmax(dp1[j+1][k+e[i]], dp1[j][k]+c[i]);
    rep(i,n) rep(j,10001-a[i]) chmax(dp2[j+a[i]], dp2[j]+h[i]);
    memset(dp3,-1,sizeof(dp3));
    dp3[0][s] = 0;
    rep(i,d) rep(j,s+1) if(~dp3[i][j])
        rep(k,j+1) if(~dp1[u][k]) chmax(dp3[i+1][min(s,j-k+o)], dp3[i][j]+dp2[dp1[u][k]]);
    int ans = -1;
    rep(i,s+1) chmax(ans, dp3[d][i]);
    return ans;
}

void input()
{
    cin >> s >> t >> u >> n >> o >> d;
    rep(i,t) cin >> e[i] >> c[i];
    rep(i,n) cin >> h[i] >> a[i];
}

int main()
{
    input();
    printf("%d\n", solve());
    return 0;
}
