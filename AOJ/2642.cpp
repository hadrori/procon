#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 n, p, q, c[1<<19];

i64 solve()
{
    for (int i = 0; i < n; i++) c[i] += p*(i+1);
    sort(c, c+n); reverse(c, c+n);
    const i64 all = p*(n*q+n*(n-1)/2);
    i64 sum = 0, ans = all;
    for (int i = 0; i < n; i++) {
        sum += c[i];
        ans = max(ans, all+sum-p*(q+2*n-i-1)*(i+1));
    }
    return ans;
}

void input()
{
    scanf("%lld%lld%lld", &n, &p, &q);
    for (int i = 0; i < n; i++) scanf("%lld", c+i);
}

int main()
{
    input();
    printf("%lld\n", solve());
    return 0;
}
