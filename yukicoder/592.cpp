#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int a, b, x, y;

double f(double z, double k) { return z>k? -1: z; }

double solve() {
    return max(f(1.*a/b*y, x)*(a+b)/a, f(1.*b/a*x, y)*(a+b)/b);
}

void input() {
    cin >> a >> b >> x >> y;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
