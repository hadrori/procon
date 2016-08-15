#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

long long n, m, p[32];

double solve()
{
    long long cnt = 0, sum = 0;
    rep(i,1<<m) if(i) {
        long long lca = 1;
        rep(j,m) if(i>>j&1) lca *= p[j]/__gcd(lca, p[j]);
        long long k = n/lca;
        if(__builtin_popcount(i)%2) {
            cnt += k;
            sum += k*(k+1)/2*lca;
        }
        else {
            cnt -= k;
            sum -= k*(k+1)/2*lca;
        }
    }
    cnt = n-cnt;
    sum = n*(n+1)/2-sum;
    if(!cnt) return 0;
    return 1.*sum/cnt;
}

bool input()
{
    cin >> n >> m;
    rep(i,m) cin >> p[i];
    return n or m;
}

int main()
{
    while(input()) printf("%.8f\n", solve());
    return 0;
}
