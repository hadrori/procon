#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, m, p, x[20010];

int solve()
{
    if(m == 1) return min(abs(p-x[0]), n-abs(p-x[0]))*100;
    sort(x,x+m);
    int ans = n;
    if(p < x[0]) {
        ans = min(ans, x[m-1]-p);
        ans = min(ans, p+n-x[0]);
    }
    else if(p > x[m-1]) {
        ans = min(ans, p-x[0]);
        ans = min(ans, n-p+x[m-1]);
    }
    p += n;
    rep(i,m) x[i+m] = x[i]+n;
    x[2*m] = x[0]+2*n;
    repi(i,m,2*m) {
        if(x[i] < p and p < x[i+1]) {
            ans = min(ans, n+x[i]-p);
            ans = min(ans, p-x[i+1-m]);
        }
        if(p < x[i]) {
            ans = min(ans, x[i]-p+x[i]-x[i+1-m]);
            ans = min(ans, p-x[i-m]+x[i-1]-x[i-m]);
        }
        else {
            ans = min(ans, p-x[i]+x[i-1]-x[i-m]);
            ans = min(ans, x[i]-p+n+x[i]-x[i+1-m]);
        }
    }
    return ans*100;
}

void input()
{
    cin >> n >> m >> p;
    rep(i,m) cin >> x[i];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
