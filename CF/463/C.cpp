#include <bits/stdc++.h>
using namespace std;
int n, a[2048][2048], i1, j1, i2, j2, m;
long long sum1[4096], sum2[4096];


void solve()
{
        m = -1;
        for (int i = 0; i < n; i++) {
                
        }

}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        scanf("%d", &a[i][j]);
                        sum1[i+j] += a[i][j];
                        sum2[n-i-1+n-j-1] += a[i][j];
                }
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
