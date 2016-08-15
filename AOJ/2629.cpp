#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;

double d;

inline double calc(double a, double b) { return a+sqrt(b*b-a*a);}

double solve()
{
        double l = 0, r = d;
        for (int _ = 0; _ < 200; _++) {
                double ml = l+(r-l)/3, mr = ml+(r-l)/3;
                if(calc(ml, d) > calc(mr, d)) r = mr;
                else l = ml;
        }
        double ans = l+sqrt(d*d-l*l);
        for (int i = 1; i <= 10; i++) {
                const double p = d*d-1.*i*i;
                if(-eps < p and p < 1+eps) ans = max(ans, i+1.);
        }
        return ans;
}

int main()
{
        cin >> d;
        cout << fixed << setprecision(12);
        cout << solve() << endl;
        return 0;
}
