#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

int h, w, si, sj, ti, tj, done[64][64];
string f[64];

int solve() {
    memset(done,-1,sizeof(done));
    int i, j;
    queue<int> q;
    done[si][sj] = 0;
    q.push(si*w+sj);
    while(!q.empty()) {
        i = q.front()/w;
        j = q.front()%w;
        q.pop();
        if(i == ti and j == tj) return done[i][j];
        rep(k,4) {
            const int ni = i+di[k], nj = j+dj[k];
            if(ni >= 0 and ni < h and nj >= 0 and nj < w and done[ni][nj] < 0 and f[ni][nj] != '#') {
                done[ni][nj] = done[i][j]+1;
                q.push(ni*w+nj);
            }
        }
    }
    assert(0);
}

void input() {
    cin >> h >> w >> si >> sj >> ti >> tj;
    si--; sj--; ti--; tj--;
    rep(i,h) cin >> f[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
