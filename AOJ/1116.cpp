#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)
const int di[] = {0,-1}, dj[] = {-1,0};

int used[10];
string p[10], q[10][4], f[4][4];

inline bool in(int i, int j) { return i>=0 and i<3 and j>=0 and j<3; }
string rot(int c, int i) { return p[i].substr(c)+p[i].substr(0,c); }

int solve(int i, int j) {
    if(j == 3) return solve(i+1, 0);
    if(i == 3) return 1;
    int sum = 0;
    rep(k,9) if(!used[k]) {
        used[k] = 1;
        rep(l,4) {
            f[i][j] = q[k][l];
            bool ok = 1;
            rep(d,2) {
                int ni = i+di[d], nj = j+dj[d];
                if(in(ni,nj) and abs(f[ni][nj][d+2] - f[i][j][d]) != 32) ok = 0;
            }
            if(ok) sum += solve(i,j+1);
        }
        used[k] = 0;
    }
    return sum;
}

void input() {
    rep(i,9) cin >> p[i];
}

int main() {
    int t; cin >> t;
    while(t--) {
        input();
        rep(i,9) rep(j,4) q[i][j] = rot(j,i);
        printf("%d\n", solve(0,0));
    }
    return 0;
}
