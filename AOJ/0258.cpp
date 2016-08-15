#include <bits/stdc++.h>
using namespace std;

int n, h[128];

int d(int i, int j)
{
        if(i == j+1) return h[j+2]-h[j];
        return h[j+1]-h[j];
}

int solve()
{
        for (int i = 0; i <= n; i++) {
                set<int> df;
                for (int j = 0; j < n-(i==n); j++) {
                        if(j == i) continue;
                        df.insert(d(i,j));
                }
                if(df.size() == 1) return h[i];
        }
        return 0;
}
bool input()
{
        scanf("%d", &n);
        if(!n) return 0;
        for (int i = 0; i < n+1; i++) scanf("%d", h+i);
        return 1;
}


int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
