#include <bits/stdc++.h>
using namespace std;
const int N = 128;

int n, m, len, q[16];
bool dp[N][1<<12];
char s[5050], p[16][32];

int solve()
{
        memset(dp,0,sizeof(dp));

        int ans = 0;
        for (int i = 0; i < len; i++) {
                dp[i%N][0] = 1;
                for (int j = 0; j < n; j++) {
                        bool ok = 1;
                        for (int k = 0; k < q[j]; k++) {
                                if(s[i+k] != p[j][k]) {
                                        ok = 0;
                                        break;
                                }
                        }
                        if(ok) {
                                for (int k = 0; k < (1<<n); k++) {
                                        const int x = 1<<j|k;
                                        if(x == k) continue;
                                        dp[(i+q[j])%N][x] |= dp[i%N][k];
                                }
                        }
                }
                ans += dp[(i+1)%N][(1<<n)-1];
                memset(dp[(i+127)%N],0,sizeof(dp[i%N]));
        }
        return ans;
}

bool input()
{
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
                scanf("%s", p[i]);
                q[i] = strlen(p[i]);
        }
        len = 0;
        for (int i = 0; i < m; i++) {
                scanf("%s", p[n]);
                int j = 0;
                while(p[n][j] != '\0') s[len++] = p[n][j++];
        }
        for (int j = 0; j < 22; j++) s[len+j] = '`';
        return n or m;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
