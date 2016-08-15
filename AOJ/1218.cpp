#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

struct node {
    int pi, pj, ci, cj, d;
    bool operator<(const node &v) const { return d > v.d; }
};

int w, h, f[8][8], done[8][8][8][8], gi, gj;

inline bool in(int i, int j) { return i >= 0 and i < h and j >= 0 and j < w; }

int solve() {
    memset(done,0,sizeof(done));
    int pi, pj, ci, cj;
    rep(i,h) rep(j,w) {
        if(f[i][j] == 2) {
            ci = i; cj = j;
            f[i][j] = 0;
        }
        else if(f[i][j] == 4) {
            pi = i; pj = j;
            f[i][j] = 0;
        }
        else if(f[i][j] == 3) {
            gi = i; gj = j;
            f[i][j] = 0;
        }
    }
    priority_queue<node> q;
    q.push((node){pi,pj,ci,cj,0});
    while(!q.empty()) {
        pi = q.top().pi; pj = q.top().pj;
        ci = q.top().ci; cj = q.top().cj;
        int d = q.top().d;
        q.pop();
        if(ci == gi and cj == gj) return d;
        if(done[pi][pj][ci][cj]) continue;
        done[pi][pj][ci][cj] = 1;
        rep(i,4) {
            int ni = pi+di[i], nj = pj+dj[i];
            if(!in(ni,nj) or f[ni][nj]) continue;
            if(ni == ci and nj == cj) {
                int nni = ni+di[i], nnj = nj+dj[i];
                if(in(nni,nnj) and !f[nni][nnj]) q.push((node){ni,nj,nni,nnj,d+1});
            }
            else q.push((node){ni,nj,ci,cj,d});
        }
    }
    return -1;
}

bool input() {
    cin >> w >> h;
    rep(i,h) rep(j,w) cin >> f[i][j];
    return w or h;
}

int main() {
    while(input()) printf("%d\n", solve());
    return 0;
}
