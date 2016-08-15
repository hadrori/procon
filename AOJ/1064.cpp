#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

struct rect { int l, r, t, b, id; };
int n, m, done[16], ans[16];
vector<rect> rs;

int get_seg(vector<rect> cs, int h, int x) {
    int r = 500;
    for(auto &c: cs) {
        if(done[c.id]) continue;
        if(c.t < h and h < c.b and c.l >= x) r = min(r, c.l);
    }
    return r;
}

vector<rect> next_comic(vector<rect> cs, int l, int r, int h) {
    vector<rect> ret;
    for(auto &c: cs) {
        if(done[c.id]) continue;
        if(l <= c.l and c.r <= r and c.b <= h) ret.push_back(c);
    }
    return ret;
}

rect find_idx(vector<rect> cs, int idx) {
    for(auto &c: cs) if(c.id == idx) return c;
    return (rect){-1,-1,-1,-1,-1};
}

int next_rect(vector<rect> cs) {
    int ret = -1;
    for(auto &c: cs) {
        if(done[c.id]) continue;
        if(ret < 0) ret = c.id;
        else {
            auto r = find_idx(cs,ret);
            if(c.l < r.l or (c.l == r.l and c.t < r.t)) ret = c.id;
        }
    }
    return ret;
}

void read_comic(vector<rect> cs) {
    // cerr << "set" << endl;
    // for(auto &c: cs) cerr << c.id << ' '; cerr << endl;
    for(int idx = -1;; idx = -1) {
        idx = next_rect(cs);
        if(idx < 0) break;
        auto c = find_idx(cs,idx);
        ans[idx] = m++;
        done[idx] = 1;
        int l = c.l, r = get_seg(cs,c.b,c.r);
        // cerr << idx+1 << ' ' << l << ' ' << r << endl;
        read_comic(next_comic(cs,l,r,c.b));
    }
}

void solve() {
    m = 1;
    memset(done,0,sizeof(done));
    read_comic(rs);
    rep(i,n) cout << ans[i] << endl;
}

bool input() {
    cin >> n;
    int x1, y1, x2, y2;
    rs.clear();
    rep(i,n) {
        cin >> x1 >> y1 >> x2 >> y2;
        rs.push_back((rect){min(x1,x2),max(x1,x2),min(y1,y2),max(y1,y2),i});
    }
    return n;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) {
        if(t) cout << endl;
        solve();
    }
    return 0;
}
