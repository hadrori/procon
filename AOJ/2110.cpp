#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int dx[] = {-1,-1,-1,0,1,1,1,0}, dy[] = {-1,0,1,1,1,0,-1,-1};
int x[2], y[2], tx, ty;

inline bool online(int fx, int fy) { return !fx or !fy or abs(fx) == abs(fy); }

bool cross(int d1, int d2, int &nx, int &ny)
{
    if(d1%4 == d2%4) return 0;
    else if(!dx[d1]) {
        nx = x[0];
        ny = (x[0]-x[1])*dx[d2]*dy[d2]+y[1];
    }
    else if(!dx[d2]) {
        nx = x[1];
        ny = (x[1]-x[0])*dx[d1]*dy[d1]+y[0];
    }
    else if(!dy[d1]) {
        nx = (y[0]-y[1])*dx[d2]*dy[d2]+x[1];;
        ny = y[0];
    }
    else if(!dy[d2]) {
        nx = (y[1]-y[0])*dx[d1]*dy[d1]+x[0];
        ny = y[1];
    }
    else {
        const int a = dx[d1]*dy[d1], b = y[0]-a*x[0], c = dx[d2]*dy[d2], d = y[1]-c*x[1];
        if((d-b)%(a-c)) return 0;
        nx = (d-b)/(a-c);
        ny = a*nx+b;
    }
    return 1;
}

int solve()
{
    int cnt = 0;
    rep(i,2) {
        const int fx = x[i]-tx, fy = y[i]-ty;
        if(!fx and !fy) return 0;
        cnt += online(fx,fy);
    }
    if(cnt) return 3-cnt;

    if(online(x[0]-x[1], y[0]-y[1])) return 3;
    int nx, ny;
    rep(d1,4) rep(d2,4) if(cross(d1, d2, nx,ny) and online(nx-tx, ny-ty)) return 3;

    return 4;
}

bool input()
{
    static int n = -1;
    if(n < 0) scanf("%d", &n);
    rep(_,!!n) scanf("%d%d%d%d%d%d", x, y, x+1, y+1, &tx, &ty);
    return n--;
}

int main()
{
    while(input()) printf("%d\n", solve());
    return 0;
}
