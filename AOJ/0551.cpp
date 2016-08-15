#include <bits/stdc++.h>
using namespace std;


int n, l, a[100010], id[100010], b[100010];

bool cmp(int i, int j) { return a[i] > a[j];}

int solve()
{
        sort(id, id+n, cmp);
        int ans = 0;
        for (int i = 0; i < n; i++) {
                int j = id[i];
                b[j] = l-a[j]+max(b[j-1], b[j+1]);
                ans = max(b[j], ans);
        }
        return ans;
}

int main()
{
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i++) scanf("%d", a+i+1), id[i] = i+1;
        printf("%d\n", solve());
        return 0;
}
