#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

struct seg { int l, r; };

int n, sn, tn, cnt[2][128];
vector<seg> s[128], t[128], u;

seg get_time()
{
    int h1, m1, h2, m2;
    scanf("%d:%d-%d:%d", &h1,&m1,&h2,&m2);
    return (seg){h1*60+m1,h2*60+m2};
}

bool in(seg a, seg b) { return b.l <= a.l and a.r <= b.r; }

int solve()
{
    rep(i,sn) {
        set<int> can;
        for(auto &e: s[i])
            rep(j,n) if(in(u[j],e))
                can.insert(j);
        for(auto &e: can) cnt[0][e]++;
    }
    rep(i,tn) {
        set<int> can;
        for(auto &e: t[i])
            rep(j,n) if(in(u[j],e))
                can.insert(j);
        for(auto &e: can) cnt[1][e]++;
    }
    int ans = 0;
    rep(i,n) ans += min(cnt[0][i], cnt[1][i]);
    return ans;
}

void input()
{
    scanf("%d", &n);
    rep(i,n) u.push_back(get_time());
    scanf("%d", &sn);
    rep(i,sn) {
        int m; scanf("%d", &m);
        rep(j,m) s[i].push_back(get_time());
    }
    scanf("%d", &tn);
    rep(i,tn) {
        int m; scanf("%d", &m);
        rep(j,m) t[i].push_back(get_time());
    }
}

int main()
{
    input();
    printf("%d\n", solve());
    return 0;
}
