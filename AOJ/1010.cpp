#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int n, f[8][8];

inline int ret(int i, int j, int v) { f[i][j] = f[j][i] = 1; return v; }

int solve(int i, int j, int m)
{
    if(m == n) return 1;
    f[i][j] = f[j][i] = 0;
    rep(ni,7) if(f[j][ni] and solve(j,ni,m+1)) return ret(i,j,1);
    return ret(i,j,0);
}

int main()
{
    while(~scanf("%d", &n)) {
        memset(f,0,sizeof(f));
        rep(i,n) {
            int x;
            scanf("%d", &x);
            f[x%10][x/10] = f[x/10][x%10] = 1;
        }
        bool ok = 0;
        rep(i,7) rep(j,7) if(f[i][j]) ok |= solve(i,j,1);
        puts(ok? "Yes": "No");
    }
    return 0;
}
