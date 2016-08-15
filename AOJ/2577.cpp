#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

int h, w, d, n, x[64], y[64], r[16], s[64], cnt[64][64];
string f[64];
bool can[64][64];

inline bool in(int i, int j) { return i>=0 and i<h and j>=0 and j<w; }

void bfs()
{
    queue<pair<int,int>> q;
    rep(i,h) rep(j,w) if(f[i][j] == 'D') q.push(make_pair(i,j));
    while(!q.empty()) {
        int i = q.front().first , j = q.front().second;
        q.pop();
        if(can[i][j]) continue;
        can[i][j] = 1;
        rep(k,4) {
            const int ni = i+di[k], nj = j+dj[k];
            if(in(ni,nj) and f[ni][nj] != '#') q.push(make_pair(ni,nj));
        }
    }
}

string solve()
{
    bfs();
    rep(k,n) {
        if(s[k] == 0) {
            rep(i,h) rep(j,w)
                if(f[i][j] != '#' and
                   abs(x[k]-j) <= r[0] and
                   abs(y[k]-i) <= r[0]) cnt[i][j]++;
        }
        else if(s[k] == d) {
            rep(i,h) rep(j,w)
                if(f[i][j] != '#' and
                   (abs(x[k]-j) > r[d-1] or
                    abs(y[k]-i) > r[d-1])) cnt[i][j]++;
        }
        else {
            rep(i,h) rep(j,w)
                if(f[i][j] != '#' and
                   abs(x[k]-j) <= r[s[k]] and
                   abs(y[k]-i) <= r[s[k]] and
                   (abs(x[k]-j) > r[s[k]-1] or
                    abs(y[k]-i) > r[s[k]-1])) cnt[i][j]++;
        }
    }

    // rep(i,h) { rep(j,w) cerr << can[i][j]; cerr << endl; }
    // cerr << endl;
    // rep(i,h) { rep(j,w) cerr << (cnt[i][j]==n); cerr << endl; }
    // cerr << endl;
    // rep(i,h) { rep(j,w) cerr << cnt[i][j] << ' '; cerr << endl; }
    
    int flag = 0;
    rep(i,h) rep(j,w) if(cnt[i][j] == n) flag |= can[i][j]+1;

    if(!flag) return "Broken";
    if(flag == 1) return "No";
    if(flag == 2) return "Yes";
    return "Unknown";
}

void input()
{
    cin >> h >> w >> d >> n;
    rep(i,h) cin >> f[i];
    rep(i,d) cin >> r[i];
    rep(i,n) cin >> x[i] >> y[i] >> s[i];
}

int main()
{
    input();
    cout << solve() << endl;
    return 0;
}
