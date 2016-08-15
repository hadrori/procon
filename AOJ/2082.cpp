#include <bits/stdc++.h>
using namespace std;

int n, m, f[1024], b[1024], bc[1<<12];

void solve()
{
        for (int i = 0; i < 1<<m; i++) bc[i] = __builtin_popcount(i);

        for (int i = 0; i < 1<<(m-1); i++) {
                for (int j = 0; j < m; j++) b[j] = i>>j&1;
                int k = i;
                bool ok = 1;
                for (int j = 0; j < n; j++) {
                        if(bc[k] == f[j]) b[j+m-1] = 0;
                        else if(bc[k] == f[j]-1) {
                                b[j+m-1] = 1;
                                k |= 1<<(m-1);
                        }
                        else {
                                ok = 0;
                                break;
                        }
                        k >>= 1;
                }
                if(ok) {
                        for (int i = 0; i < n+m-1; i++) printf("%d", b[i]);
                        puts("");
                        return;
                }
        }
        puts("Goofy");
}

bool input()
{
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%d", f+i);
        return n or m;
}

int main()
{
        while(input()) solve();
        return 0;
}
