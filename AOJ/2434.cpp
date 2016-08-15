#include <bits/stdc++.h>
using namespace std;
#define double long double
const int pt[] = {5, 3, 2};

int n, m, val[2048][4];
double sum[2048], dp[4][2048][2][4];

double exp(int v, int k) { return (dp[v][k][n&1][0]+dp[v][k][n&1][1]+dp[v][k][n&1][2])*pt[v]-dp[v][k][n&1][3];}

double solve()
{
        sum[0] = 1;
        for (int i = 0; i < m; i++)
                for (int j = i; j >= 0; j--) {
                        sum[j+1] += sum[j]/3;
                        sum[j] *= 2./3;
                }
        for (int i = 0; i < m; i++) sum[i+1] += sum[i];

        for (int v = 0; v < 3; v++) {
                for (int i = 0; i <= m; i++) {
                        dp[v][i][1][0] = dp[v][i][1][3] = 1;
                        for (int j = 1; j < n; j++) {
                                const int cj = j&1, nj = cj^1;
                                const int w = min((val[0][v]*i+val[j][v]-1)/val[j][v]-1, m);
                                const double win = i? sum[w]: 0, lose = 1-win;
                                for (int k = 0; k < 3; k++) {
                                        if(k < 2) dp[v][i][nj][k+1] += dp[v][i][cj][k]*lose;
                                        dp[v][i][nj][k] += dp[v][i][cj][k]*win;
                                }
                                dp[v][i][nj][3] = dp[v][i][cj][3]*lose;
                                for (int k = 0; k < 4; k++) dp[v][i][cj][k] = 0;
                        }
                }
        }

        double ans = -100;
        for (int i = 0; i <= m; i++)
                for (int j = 0; j <= m-i; j++)
                        ans = max(ans, exp(0,i)+exp(1,j)+exp(2,m-i-j));
        return ans;
}

void input()
{
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
                for (int j = 0; j < 3; j++)
                        scanf("%d", val[i]+j);
}

int main()
{
        input();
        printf("%.12Lf\n", solve());
        return 0;
}
