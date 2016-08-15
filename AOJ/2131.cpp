#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const double eps = 1e-10, pi = acos(-1.);
double e;

void solve() {
    repi(i,1,114514) {
        int a = pi*i, b = a+1;
        double x = 1.*a/i, y = 1.*b/i;
        if(abs(pi-x) < e) {
            cout << a << '/' << i << endl;
            return;
        }
        if(abs(pi-y) < e) {
            cout << b << '/' << i << endl;
            return;
        }
    }
}

bool input() {
    cin >> e;
    return abs(e)>eps;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) solve();
    return 0;
}
