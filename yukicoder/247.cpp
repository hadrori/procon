#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

int f[4][4], g[4][4];
inline bool in(int i, int j) { return 0 <= i and i < 4 and 0 <= j and j < 4; }

int solve(int i, int j, int used) {
    int ok = 1;
    rep(i,4) rep(j,4) if(f[i][j] != g[i][j]) ok = 0;
    if(ok) return 1;
    rep(d,4) {
        const int ni = i+di[d], nj = j+dj[d];
        if(in(ni,nj) and g[ni][nj] == f[i][j]) {
            swap(g[i][j], g[ni][nj]);
            if(solve(ni,nj,1<<f[i][j]|used)) return 1;
            swap(g[i][j], g[ni][nj]);
        }
    }
    return 0;
}

void input() {
    rep(i,4) rep(j,4) {
        scanf("%d", f[i]+j);
        g[i][j] = i*4+j+1;
    }
    g[3][3] = 0;
}

int main() {
    input();
    puts(solve(3,3,0)? "Yes": "No");
    return 0;
}
