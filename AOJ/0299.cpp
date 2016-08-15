#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, m, p, x[20010];

int solve()
{
    sort(x,x+m);
    int ans = n;
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
