#include <bits/stdc++.h>
using namespace std;
#define double long double
const double eps = 1e-8;
const int N = 86400;

int n, m, sc[100010];

bool ok(double x)
{
        double sum = m, l = m;
        double c[2] = {};
        for (int i = 0; i < N*2; i++) {
                sum -= sc[i%N];
                sum += x;
                sum = min(sum, l);
                if(sum < eps) return 0;
                if((i+1)%N == 0) c[i/N] = sum;
        }
        return c[0]-eps < c[1];
}

double solve()
{
        double lb = 0, ub = 1e6, mid;
        for (int _ = 0; _ < 64; _++) {
                mid = (lb+ub)/2;
                if(ok(mid)) ub = mid;
                else lb = mid;
        }
        return ub;
}

bool input()
{
        cin >> n >> m;
        memset(sc,0,sizeof(sc));
        for (int i = 0; i < n; i++) {
                int l, r, k;
                cin >> l >> r >> k;
                for (int j = l; j < r; j++) sc[j] = k;
        }
        return n or m;
}

int main()
{
        cin.tie(0);
        cout << fixed << setprecision(8);
        while(input()) cout << solve() << endl;
        return 0;
}
