#include <bits/stdc++.h>
using namespace std;

int n, k[10010];

void solve()
{
        if(*max_element(k,k+n) < 2) {
                puts("NA");
                return;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) if(k[i]) sum++;
        printf("%d\n", sum+1);
}

bool input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", k+i);
        return n;
}

int main()
{
        while(input()) solve();
        return 0;
}
