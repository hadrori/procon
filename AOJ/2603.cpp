#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
i64 s, n, m, x[2048], sum[2048], t[2048], p[2048];

inline void chmin(i64 &a, i64 b) { a = b<0? a: min(a,b); }
inline i64 calc(int l, int r) { return (r-l)*t[r-1]-(sum[r]-sum[l]); }

i64 solve()
{
    for (int i = 0; i < n; i++) t[i] -= x[p[i]-1];
    sort(t,t+n);
    for (int i = 1; i < n; i++) t[i] -= t[0];
    t[0] = 0;
    partial_sum(t,t+n,sum+1);

    return ans;
}

void input()
{
    scanf("%lld%lld%lld", &s, &n, &m);
    for (int i = 0; i < s; i++) scanf("%lld", x+i);
    for (int i = 0; i < n; i++) scanf("%lld%lld", t+i, p+i);
}

int main()
{
    input();
    printf("%lld\n", solve());
    return 0;
}
