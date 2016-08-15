#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

int h, w, t, si, sj, ti, tj, done[16][16];
string s[16];

inline bool in(int i, int j) { return 0 <= i and i < h and 0 <= j and j < w; }

void get_pos() {
    rep(i,h) rep(j,w) {
        if(s[i][j] == 'S') si = i, sj = j;
        if(s[i][j] == 'G') ti = i, tj = j;
    }
}

bool can(int x) {
    memset(done,0,sizeof(done));
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
    q.emplace(0,si,sj);
    int i, j, d;
    while(!q.empty()) {
        tie(d,i,j) = q.top(); q.pop();
        if(done[i][j]) continue;
        if(d > t) break;
        if(i == ti and j == tj) return 1;
        done[i][j] = 1;
        rep(k,4) {
            const int ni = i+di[k], nj = j+dj[k];
            if(in(ni,nj)) {
                if(s[ni][nj] == '#') q.emplace(d+x,ni,nj);
                else q.emplace(d+1,ni,nj);
            }
        }
    }
    return 0;
}

void solve() {
    get_pos();
    int lb = 1, ub = t, mid;
    while(ub-lb > 1) {
        mid = (lb+ub)/2;
        if(can(mid)) lb = mid;
        else ub = mid;
    }
    cout << lb << endl;
}

void input() {
    cin >> h >> w >> t;
    rep(i,h) cin >> s[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
