#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
int w, h, n, x[100010], y[100010], cx[100010], cy[100010];

i64 dist(int ax, int ay)
{
        i64 ret = 0, mx = 0;
        for (int i = 0; i < n; i++) {
                const i64 d = abs(1LL*ax-cx[i])+abs(1LL*ay-cy[i]);
                ret += d;
                mx = max(mx, d);
        }
        return ret*2-mx;
}

void solve()
{
        sort(x, x+n);
        sort(y, y+n);
        i64 ans = 123456789012345678LL, tx = -1, ty = -1;
        for (int i = max(n/2-1, 0); i < min(n/2+1, n); i++) {
                for (int j = max(n/2-1, 0); j < min(n/2+1, n); j++) {
                        const i64 d = dist(x[i], y[j]);
                        if(ans > d) {
                                ans = d;
                                tx = x[i];
                                ty = y[j];
                        }
                }
        }

        printf("%lld\n%lld %lld\n", ans, tx, ty);
}

void input()
{
        scanf("%d%d%d", &w, &h, &n);
        for (int i = 0; i < n; i++) {
                scanf("%d%d", x+i, y+i);
                cx[i] = x[i];
                cy[i] = y[i];
        }
}

int main()
{
        input();
        solve();
        return 0;
}
