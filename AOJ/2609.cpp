#include <bits/stdc++.h>
using namespace std;

typedef complex<long long> point;
const long double eps = 1e-8;
long long w, h, v, m, r;
point s, t;

long long calc(long long x)
{
        x -= s.real();
        const long long rr = r*r, xx = x*x;
        const long long y = (long long)(sqrt(rr-xx)+eps);
        const long long a = y+s.imag(), b = s.imag()-y, c = a%(2*h), d = b%(2*h);
        const int sig = d<0? -1: 1;
        long long ret = a/(2*h)*2-b/(2*h)*2 + c/(2*h-t.imag())+(c/t.imag()>0)-d/(2*h-t.imag())-sig*(abs(d)/t.imag()>0);
        return ret;
}

long long solve()
{
        vector<long long> d = {2*(w-t.real()), 2*t.real()};
        r = v*m;
        long long ans = 0;
        for (long long x = t.real(), i = 0; x-s.real() <= r; x+=d[(i++)&1]) ans += calc(x);
        for (long long x = t.real(), i = 1; s.real()-x <= r; x-=d[(i++)&1]) ans += calc(x);
        ans -= calc(t.real());
        return ans;
}

void input()
{
        long long x, y, p, q;
        cin >> w >> h >> v >> m >> x >> y >> p >> q;
        s = point(x,y);
        t = point(p,q);
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
