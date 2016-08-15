#include <bits/stdc++.h>
using namespace std;

int n, h, f[512][512][512];

int solve()
{
        memset(f,0,sizeof(f));
        int sum = n*n*n-h*n;
        while(h--) {
                int a, b;
                char s[4];
                scanf("%s %d %d", s, &a, &b);
                if(s[0] == 'x' and s[1] == 'y');
        }
}

bool input()
{
        scanf("%d%d", &n, h);
        return n or h;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
