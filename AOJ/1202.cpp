#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int n, h, w, f[512][512];
vector<pair<double,int>> xs, ys;
int lxi[128], rxi[128], lyi[128], ryi[128];
double lx[128], rx[128], ly[128], ry[128];


double solve()
{
    xs.clear(); ys.clear();
    rep(i,n) {
        xs.push_back(make_pair(lx[i], i));
        xs.push_back(make_pair(rx[i], i+n));
        ys.push_back(make_pair(ly[i], i));
        ys.push_back(make_pair(ry[i], i+n));
    }
    sort(begin(xs),end(xs));
    sort(begin(ys),end(ys));
    rep(i,2*n) {
        if(xs[i].second < n) lxi[xs[i].second] = i;
        else rxi[xs[i].second-n] = i;
        if(ys[i].second < n) lyi[ys[i].second] = i;
        else ryi[ys[i].second-n] = i;
        
    }
    memset(f,0,sizeof(f));
    rep(i,n) {
        f[lyi[i]][lxi[i]]++;
        f[lyi[i]][rxi[i]]--;
        f[ryi[i]][lxi[i]]--;
        f[ryi[i]][rxi[i]]++;
    }
    rep(i,2*n) rep(j,2*n) f[i][j+1] += f[i][j];
    rep(i,2*n) rep(j,2*n) f[i+1][j] += f[i][j];
    double ans = 0;
    rep(i,2*n-1) rep(j,2*n-1) if(f[i][j]) ans += (xs[j+1].first-xs[j].first)*(ys[i+1].first-ys[i].first);
    return ans;
}

bool input()
{
    cin >> n;
    rep(i,n) {
        double x, y, r;
        cin >> x >> y >> r;
        lx[i] = x-r;
        rx[i] = x+r;
        ly[i] = y-r;
        ry[i] = y+r;
    }
    return n;
}

int main()
{
    cout << fixed << setprecision(2);
    for(int t = 1; input(); t++) cout << t << ' ' << solve() << endl;
    return 0;
}
