#include <bits/stdc++.h>
using namespace std;

int n, a[8], rv[8], tmp[8], len;
vector<int> buf[8];

int dfs(int i, int m, int s, int p)
{
        if(p > len) {
                memcpy(rv, tmp, sizeof(rv));
                len = p;
        }
        if(p == a[m]) return p;
        if(i == m) return p;
        tmp[i] = -1;
        int res = dfs(i+1,m,s,p);
        for (int j = 0; j < (int)buf[i].size(); j++) {
                if(__builtin_popcount(buf[i][j]&s)) continue;
                tmp[i] = j;
                int t = dfs(i+1,m,buf[i][j]|s,p+1);
                res = max(res, t);
        }
        return res;
}

long long solve()
{
        sort(a, a+n);
        reverse(a, a+n);
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
                memset(rv,-1,sizeof(rv));
                len = 0;
                int res = dfs(0,i,0,0);
                ans += a[i]-res;

                for (int j = 0; j < i; j++)
                        if(~rv[j]) buf[j][rv[j]] |= 1<<i;

                for (int j = res; j < min(a[i], n); j++) buf[i].push_back(1<<i);
        }
        return ans;
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", a+i);
}

int main()
{
        input();
        printf("%lld\n", solve());
        return 0;
}
