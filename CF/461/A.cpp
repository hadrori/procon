#include <bits/stdc++.h>
using namespace std;

int n, a[400000];

long long solve()
{
        sort(a, a+n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
                ans += 1LL*a[i]*(i+2);
        ans -= a[n-1];
        return ans;
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
                scanf("%d", a+i);

}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
