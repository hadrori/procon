#include <bits/stdc++.h>
using namespace std;

inline void chmax(double &x, double y) { x = max(x,y);}

int n, m;
double p[16][16], dp[1<<16][16][16];

double solve()
{
        for (int i = 0; i < m; i++) {
                for (int j = 0; j < 1<<n; j++) {
                        for (int k = 0; k < n; k++) {
                                if(!(j>>k&1)) continue;
                                dp[j][k][i+1] = dp[j][k][i]*p[k][i];
                                for (int l = 0; l < n; l++) {
                                        if(j>>l&1) continue;
                                        dp[1<<l|j][l][i] += dp[j][k][i]*(1.-p[k][i]);
                                }
                        }
                }
        }

        double ans = 0;
        return ans;
}

void input()
{
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                        scanf("%lf", p[i]+j);
}

int main()
{
        input();
        printf("%.12f\n", solve());
        return 0;
}
