#include "bits/stdc++.h"
using namespace std;
 
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
 
int mem[32][32][32][32];
 
inline bool in(int lx, int ly, int rx, int ry, int x, int y) { return lx < x and x < rx and ly < y and y < ry; }
int w, h, n, x[32], y[32];
 
int rec(int lxi, int lyi, int rxi, int ryi) {
    int &ret = mem[lxi][lyi][rxi][ryi];
    if(~ret) return ret;
    ret = 0;
    const int lx = x[lxi], ly = y[lyi], rx = x[rxi], ry = y[ryi];
    rep(i,n) if(in(lx,ly,rx,ry,x[i],y[i])) {
        int sum = rx-lx+ry-ly-3;
        sum += rec(lxi,lyi,i,i);
        sum += rec(i,lyi,rxi,i);
        sum += rec(lxi,i,i,ryi);
        sum += rec(i,i,rxi,ryi);
        ret = max(ret, sum);
    }
    return ret;
}
 
void solve() {
    x[n+1] = w+1;
    y[n+1] = h+1;
    memset(mem,-1,sizeof(mem));
    cout << rec(n,n,n+1,n+1) << endl;
}
 
void input() {
    cin >> w >> h >> n;
    rep(i,n) cin >> x[i] >> y[i];
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
