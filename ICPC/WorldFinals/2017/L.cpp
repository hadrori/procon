#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

struct kakko {
    int r, c, t;
    bool operator<(const kakko &k) const {
        if(c != k.c) return c < k.c;
        return r < k.r;
    }
};

int n;
vector<kakko> ks;

void solve() {
}

void input() {
    cin >> n;
    rep(i,n) {
        int r, c;
        cin >> r >> c;
        ks.push_back((kakko){r,c,0});
        cin >> r >> c;
        ks.push_back((kakko){r,c,1});
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
