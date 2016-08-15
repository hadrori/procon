#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int n, k, ans[32];

int main()
{
    k = 1;
    rep(i,30) {
        ans[i+1] = k+ans[i];
        if(i%2) k *= 3;
    }
    while(~scanf("%d", &n)) printf("%d\n", ans[n]);
    return 0;
}
