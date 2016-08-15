#include <bits/stdc++.h>
using namespace std;

int n, m, pr[32], cr[32], num[1<<20];

int solve()
{
        int ans = n;
        for (int s = 0; s < 1<<n; s++) {
                if(num[s] > ans) continue;
                int sum = 0;
                for (int i = 0; i < n; i++) {
                        if(s>>i&1) {
                                if((pr[i]&s)==pr[i]) sum += cr[i];
                                else {
                                        sum = -1;
                                        break;
                                }
                        }
                }
                if(sum >= m) ans = num[s];
        }
        return ans;
}

bool input()
{
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
                int k, l; scanf("%d%d", cr+i, &k);
                pr[i] = 0;
                for (int j = 0; j < k; j++) {
                        scanf("%d", &l);
                        pr[i] |= 1<<l;
                }
        }
        return n or m;
}

int main()
{
        for (int i = 0; i < 1<<20; i++) num[i] = __builtin_popcount(i);
        while(input()) printf("%d\n", solve());
        return 0;
}
