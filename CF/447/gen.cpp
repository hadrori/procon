#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;

int main(){
    int n = 1000, m = 1000;
    cout << n << ' ' << m << endl;
    rep(i,n) cout << i+1 << ' '; cout << endl;
    rep(i,m) cout << i%2+1 << ' ' << i%100+1 << ' ' << 600+(i%100)+10 << endl;
    return 0;
}
