#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;
const double pi = acos(-1.);

int n;
double d, l[128], r[128], t[128];

point rot(const point &p, const double th) { return point(cos(th)*p.real()-sin(th)*p.imag(), sin(th)*p.real()+cos(th)*p.imag());}

void solve()
{
        double th = 0.;

        point lp(-d,0), rp(d,0);
        d *= 2;
        for (int i = 0; i < n; i++) {
                t[i] *= pi/180.;
                double dl = l[i]*t[i], dr = r[i]*t[i];
                if(l[i] == r[i]) {
                        const point dp = rot(dl, th+pi/2);
                        lp += dp;
                        rp += dp;
                }
                else if(l[i] == 0) {
                        th += dr/d;
                        rp = polar(d, th)+lp;
                }
                else if(r[i] == 0) {
                        th -= dl/d;
                        lp = -polar(d, th)+rp;
                }
                else {
                        const point o = (r[i]*lp-l[i]*rp)/(r[i]-l[i]);
                        double dth = dr/abs(rp-o);
                        if((l[i] < r[i] and r[i] < 0) or (0 < r[i] and r[i] < l[i])) dth *= -1;
                        rp = polar(abs(rp-o), arg(rp-o)+dth)+o;
                        lp = polar(abs(lp-o), arg(lp-o)+dth)+o;
                        th += dth;
                }
        }
        point p = (lp+rp)/2.;
        printf("%.5f\n%.5f\n", p.real(), p.imag());
}

bool input()
{
        scanf("%d%lf", &n, &d);
        for (int i = 0; i < n; i++) scanf("%lf%lf%lf", l+i, r+i, t+i);
        return n or d;
}

int main()
{
        while(input()) solve();
        return 0;
}
