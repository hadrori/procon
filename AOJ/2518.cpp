#include <bits/stdc++.h>
using namespace std;

map<int,int> id;
int n, f[2048];

inline int mkhs(int l, int r, int d) { return (l<<16)+(r<<4)+d; }

int solve()
{
        for (int d = n-1; d >= 0; d--) {
                const int b = (1<<d)-1;
                for (int i = b; i < b+(1<<d); i++) {
                        const int l = f[2*i+1], r = f[2*i+2], h = mkhs(l,r,d);
                        if(l == r) f[i] = l;
                        else if(id.count(h)) f[i] = id[h];
                        else f[i] = id[h] = id.size()+1;
                }
        }
        return id.size();
}

void input()
{
        scanf("%d", &n);
        char s[1100];
        scanf("%s", s);
        for (int i = 0; i < 1<<n; i++) f[i+(1<<n)-1] = s[i]-'0';
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
