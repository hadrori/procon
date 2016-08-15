#include <bits/stdc++.h>
using namespace std;

int n, b[200010];

void solve()
{
        sort(b,b+n);
        cout << b[n-1]-b[0] << " ";        
        long long l = upper_bound(b,b+n,b[0])-b, r = b+n-lower_bound(b,b+n,b[n-1]);
        long long ans = l*r;
        if(b[0] == b[n-1]) ans = 1LL*n*(n-1)/2;
        cout << ans << endl;
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                scanf("%d", b+i);
        }
}

int main()
{
        input();
        solve();
        return 0;
}
