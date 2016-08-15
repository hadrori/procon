#include <bits/stdc++.h>
using namespace std;
const int di[] = {1,0}, dj[] = {0,1};
int h, w, n, f[1024][1024], dp[1024][1024];

void solve()
{
        memset(dp,0,sizeof(dp));
        dp[0][0] = n-1;
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        dp[i][j+1] += (dp[i][j]+ f[i][j])/2;
                        dp[i+1][j] += (dp[i][j]+!f[i][j])/2;
                }
        }
        int ci = 0, cj = 0;
        while(ci < h and cj < w) {
                f[ci][cj] ^= dp[ci][cj]%2;
                int ni = ci+di[f[ci][cj]], nj = cj+dj[f[ci][cj]];
                ci = ni; cj = nj;
        }
        printf("%d %d\n", ci+1, cj+1);
}

bool input()
{
        scanf("%d%d%d", &h, &w, &n);
        for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                        scanf("%d", f[i]+j);
        return h or w or n;
}

int main()
{
        while(input()) solve();
        return 0;
}
