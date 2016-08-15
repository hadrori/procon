#include <bits/stdc++.h>
using namespace std;

int t, d, a, b, x, y;

double solve()
{
    double ans = 1e9;
    for (int i = 0; x*i <= d; i++)
        for (int j = 0; x*i+y*j <= d; j++)
            ans = min(ans, abs(t-1.*(a*x*i+b*y*j)/(x*i+y*j)));
    return ans;
}

void input()
{
    scanf("%d%d%d%d%d%d", &t, &d, &a, &b, &x, &y);
}

int main()
{
    input();
    printf("%.8f\n", solve());
    return 0;
}
