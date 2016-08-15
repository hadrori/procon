#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

inline void chmin(int &x, int y) { x = min(x,y); }
const int inf = 1e9;
map<string,int> id;
int n, m, a, b, c, wf[512][512];

int index(string &s) { return id.count(s)? id[s]: id[s]=id.size()-1; }

int solve()
{
    rep(k,n) rep(i,n) rep(j,n) chmin(wf[i][j], wf[i][k]+wf[k][j]);
    return wf[0][1]+wf[1][2];
}

void init()
{
    a = 0; b = 1; c = 2;
    id.clear();
    rep(i,512) rep(j,512) wf[i][j] = inf;
}

bool input()
{
    init();
    cin >> n >> m;
    if(!n and !m) return 0;
    string s, t, u;
    cin >> s >> t >> u;
    index(s); index(t); index(u);
    int d, e;
    rep(i,m) {
        cin >> s >> t >> d >> e;
        wf[index(s)][index(t)] = d/40+e;
        wf[index(t)][index(s)] = d/40+e;
    }
    return 1;
}

int main()
{
    while(input()) printf("%d\n", solve());
    return 0;
}
