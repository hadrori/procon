#include <bits/stdc++.h>
using namespace std;

int h, w, f[32][32];

int dfs(int i, int j)
{
        if(j == w) return dfs(i+1,0);
        if(i == h) return 1;
        if(f[i][j]) return dfs(i,j+1);

        int ret = 0;
        // tate
        if(i < h-1 and !f[i+1][j] and
           (!i or
            ((!j or
              ((f[i-1][j-1]&2)|(f[i-1][j]&1)) != 3) and
             (j == w-1 or
              ((f[i-1][j]&2)|(f[i-1][j+1]&1)) != 3)))) {
                f[i][j] = 4;
                f[i+1][j] = 3;
                ret += dfs(i,j+1);
                f[i][j] = f[i+1][j] = 0;
        }

        // yoko
        if(j < w-1 and !f[i][j+1] and
           (!i or
            ((!j or
              ((f[i-1][j-1]&2)|(f[i-1][j]&1)) != 3) and
             (j == w-2 or
              ((f[i-1][j+1]&2)|(f[i-1][j+2]&1)) != 3)))) {
                f[i][j] = 1;
                f[i][j+1] = 2;
                ret += dfs(i,j+2);
                f[i][j] = f[i][j+1] = 0;
        }
        return ret;
}

int solve()
{
        memset(f,0,sizeof(f));
        return dfs(0,0);
}

bool input()
{
        scanf("%d%d", &h, &w);
        return h or w;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
