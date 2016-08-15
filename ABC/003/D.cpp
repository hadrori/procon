#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
const i64 mod = 1e9+7;

inline void sub(i64 &x, i64 y) { x = (x-y+mod)%mod; }
inline void add(i64 &x, i64 y) { x = (x+y)%mod; }

i64 extgcd(i64 a, i64 b, i64& x, i64& y) {
    i64 g = a; x = 1, y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

i64 inv(i64 a) {
    i64 x, y;
    if (extgcd(a, mod, x, y) != 1) return 0;
    return (x % mod + mod) % mod;
}

i64 r, c, h, w, d, l, f[1024];
inline i64 binom(i64 n, i64 m) {
    if (n < m) return 0;
    return f[n]*inv(f[m])%mod*inv(f[n-m])%mod;
}

inline i64 calc(i64 x, i64 y) { if(x <= 0 or y <= 0) return 0; return binom(x*y,d)*binom(x*y-d,l)%mod; }

i64 solve() {
    f[0] = 1;
    rep(i,1023) f[i+1] = f[i]*(i+1)%mod;

    i64 res = binom(h*w,d)*binom(h*w-d,l)%mod;
    sub(res, calc(h-1,w)*2%mod);
    sub(res, calc(h,w-1)*2%mod);
    add(res, calc(h-1,w-1)*4%mod);
    add(res, calc(h-2,w));
    add(res, calc(h,w-2));
    sub(res, calc(h-2,w-1)*2%mod);
    sub(res, calc(h-1,w-2)*2%mod);
    add(res, calc(h-2,w-2));
    return (r-h+1) * (c-w+1) * res % mod;
}

void input() {
    cin >> r >> c >> h >> w >> d >> l;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
