#include <bits/stdc++.h>
using namespace std;

#define double long double

dobule a, b, c, d;

bool ok(double x)
{
        double e = a-x, f = b-x;
        double c = abs(e)>1e-9? x: 0;
}

double solve()
{
        double lb = 0, ub = 2e9;
        while(ub-lb>1e-9) {
                double m = (lb+ub)/2;
                if(ok(m)) ub = m;
                else lb = m;
        }
        return (lb+ub)/2;
}

void input()
{
        cin >> a >> b >> c >> d;
}

int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        cout << fixed << setprecision(12);
        input();
        cout << solve() << endl;
        return 0;
}
