#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
using pii = pair<int,int>;

vector<pii> v, w, matching;

bool valid(int i, int j) {
    return v[i].first <= w[j].first && v[i].second <= w[j].second;
}

i64 area(int i, int j) {
    return 1LL * (w[j].first - v[i].first) * (w[j].second - v[i].second);
}

void search(int lb, int ub, int l, int r) {
    if(ub - lb < 1 || r - l < 1) return;
    int mid = (lb+ub)/2, m = -1;

    int x = v[mid].first, y = v[mid].second;
    if(x > w[r-1].first) search(lb, mid, l, r);
    else if(y > w[l].second) search(mid+1, ub, l, r);

    i64 ma = -1;
    repi(i,l,r) if(valid(mid, i)) {
        i64 a = area(mid, i);
        if(a > ma) {
            ma = a;
            m = i;
        }
    }

    matching.emplace_back(mid, m);
    search(lb, mid, l, m+1);
    search(mid+1, ub, m, r);
}

i64 solve() {
    search(0, v.size(), 0, w.size());
    i64 ans = 0;
    for (auto &e: matching) ans = max(ans, area(e.first, e.second));
    return ans;
}

void normalize_v() {
    sort(begin(v),end(v));
    int my = 1e9+10;
    vector<pii> tv;
    for (auto &e: v) {
        if(e.second >= my) continue;
        tv.push_back(e);
        my = e.second;
    }
    v = tv;
}

void normalize_w() {
    sort(begin(w),end(w));
    reverse(begin(w),end(w));
    int my = 0;
    vector<pii> tw;
    for (auto &e: w) {
        if(e.second <= my) continue;
        tw.push_back(e);
        my = e.second;
    }
    reverse(begin(tw),end(tw));
    w = tw;
}

void input() {
    int m, n, p, d;
    cin >> m >> n;
    rep(i,m) {
        cin >> p >> d;
        v.emplace_back(p, d);
    }
    rep(i,n) {
        cin >> p >> d;
        w.emplace_back(p, d);
    }
    normalize_v();
    rep(i,v.size()) w.push_back(v[i]);
    normalize_w();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
