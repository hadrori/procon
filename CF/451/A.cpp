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
const string a = "Akshat", b = "Malvika";
int n, m;

string solve(){
    n = m = min(n,m);
    return n%2? a: b;
}

void input(){
    cin >> n >> m;
}

int main(){
    cin.sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
