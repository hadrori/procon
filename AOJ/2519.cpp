#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1,-1,-1,0,1,1,1,0}, dj[] = {-1,0,1,1,1,0,-1,-1};

#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

char s[8][8], f[128][16];
int n, t, p[128], len[128], cnt[128], used[8][8], dp[10010];

inline bool in(int i, int j) { return i >= 0 and i < 4 and j >= 0 and j < 4; }

void dfs(int i, int j, int id, int cur)
{
    if(f[id][cur] != s[i][j] or used[i][j]) return;
    if(cur == len[id]-1) {
        cnt[id]++;
        return;
    }

    used[i][j] = 1;
    rep(d,8) {
        const int ni = i+di[d], nj = j+dj[d];
        if(in(ni,nj)) dfs(ni,nj,id,cur+1);
    }
    used[i][j] = 0;
}

int solve()
{
    rep(k,n) rep(i,4) rep(j,4) dfs(i,j,k,0);
    rep(i,n) {
        int m = cnt[i];
        for (int k = 1; m > 0; k <<= 1) {
            const int h = min(k,m);
            for (int j = t; j >= h*len[i]; j--)
                dp[j] = max(dp[j], dp[j-h*len[i]]+h*p[i]);
            m -= h;
        }
    }
    return dp[t];
}

void input()
{
    scanf("%d", &n);
    rep(i,n) {
        scanf("%s %d", f[i], p+i);
        len[i] = strlen(f[i]);
    }
    rep(i,4) scanf("%s", s[i]);
    scanf("%d", &t);
}

int main()
{
    input();
    printf("%d\n", solve());
    return 0;
}
