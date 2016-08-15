#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n;
pair<int,int> se[30010];

void solve() {
    vector<pair<int,int>> ps;
    rep(i,n) {
        se[i].first = se[i].first/5*5;
        se[i].second = (se[i].second+4)/5*5;
        if(se[i].second%100 == 60) se[i].second = se[i].second/100*100+100;
    }
    sort(se,se+n);
    pair<int,int> s(-1,-1);
    rep(i,n) {
        if(se[i].first <= s.second) s.second = max(s.second, se[i].second);
        else {
            if(s.first >= 0) ps.push_back(s);
            s = se[i];
        }
    }
    ps.push_back(s);
    for (auto &e: ps) printf("%04d-%04d\n", e.first, e.second);
}

void input() {
    scanf("%d", &n);
    rep(i,n) scanf("%d-%d", &se[i].first, &se[i].second);
}

int main() {
    input();
    solve();
    return 0;
}
