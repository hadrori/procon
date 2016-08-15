#include <bits/stdc++.h>
using namespace std;
const int inv[] = {13,17,19,23};

int n, q[128][32], p[65536];

int solve()
{
        memset(p,0,sizeof(p));
        for (int j = 1; j < 25; j++) {
                if(j == 13 or j == 17 or j == 19 or j == 23) continue;
                for (int i = 0; i < 55440; i++) p[i] += q[j][i%j];
        }

        int sum = *max_element(p,p+55440);
        for (int i = 0; i < 4; i++) sum += *max_element(q[inv[i]], q[inv[i]]+inv[i]);
        return sum;
}

bool input()
{
        scanf("%d", &n);
        memset(q,0,sizeof(q));
        for (int i = 0; i < n; i++) {
                int d, t, a; scanf("%d%d", &d, &t);
                for (int j = 0; j < d; j++) {
                        scanf("%d", &a);
                        q[d][(j-t+d)%d] += a;
                }
        }

        return n;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
