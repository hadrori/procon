#include <bits/stdc++.h>
using namespace std;
const int m = 100010;

int n, d, x, p[10][10], dp[11][m];

int solve()
{
        for (int i = 0; i < d; i++) {
                for (int j = 0; j < n; j++) {
                        for (int k = 1; k < d-i; k++) {
                                
                        }
                }
        }

}

void input()
{
        scanf("%d%d%d", &n, &d, &x);
        for (int i = 0; i < d; i++)
                for (int j = 0; j < n; j++)
                        scanf("%d", p[j]+i);
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
