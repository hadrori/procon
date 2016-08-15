#include <bits/stdc++.h>
using namespace std;

inline void chmax(int &a, int b) { a = a<0? b: max(a,b);}

int n, d, t[256], a[256], b[256], c[256], dp[256][256];

int solve()
{
        memset(dp,-1,sizeof(dp));
        for (int i = 0; i < n; i++) if(a[i] <= t[0] and t[0] <= b[i]) dp[0][i] = 0;
        for (int i = 1; i < d; i++) {
                for (int j = 0; j < n; j++) {
                        if(a[j] > t[i] or t[i] > b[j]) continue;
                        for (int k = 0; k < n; k++) {
                                if(dp[i-1][k] < 0) continue;
                                dp[i][j] = max(dp[i][j], dp[i-1][k]+abs(c[j]-c[k]));
                        }
                }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans = max(ans, dp[d-1][i]);
        return ans;
}

void input()
{
        scanf("%d%d", &d, &n);
        for (int i = 0; i < d; i++) scanf("%d", t+i);
        for (int i = 0; i < n; i++) scanf("%d%d%d", a+i, b+i, c+i);
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
