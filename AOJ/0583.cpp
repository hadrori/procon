#include <bits/stdc++.h>
using namespace std;

int n, a[4];

void solve()
{
        int g = a[0];
        for (int i = 1; i < n; i++) g = __gcd(g,a[i]);
        vector<int> ps;
        vector<int> ans;
        for (int i = 1; i*i <= g; i++)
                if(g%i == 0) {
                        ans.push_back(i);
                        if(i != g/i) ans.push_back(g/i);                        
                }
        sort(begin(ans),end(ans));
        for(auto &e: ans) printf("%d\n", e);
}


int main()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a+i);
        solve();
        return 0;
}
