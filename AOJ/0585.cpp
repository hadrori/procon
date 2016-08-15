#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

typedef complex<int> point;
namespace std {
bool operator < (const point& a, const point& b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); }
}

int S[500010], n, s, t, m, d, i, j;
point ps[500010];

int solve() {
    s = 0; t = 1; m = 2; S[0] = 0, S[1] = 1;
    sort(ps, ps+n);
    int d = norm(ps[s]-ps[t]);
    rep(i,n) repi(j,i+1,n) {
        if (real(ps[i]-ps[j])*real(ps[i]-ps[j]) > d) break;
        d = min(d, norm(ps[i]-ps[j]));
    }
    return d;
}

void input() {
    scanf("%d", &n);
    int x, y;
    rep(i,n) {
        scanf("%d %d", &x, &y);
        ps[i] = point(x, y);
    }
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
