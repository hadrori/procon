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

int solve(){
    int a[] = {0,2,4,6,8};
    int k = 0;
    cout << ++a[++a[k++]] << endl;
    rep(i,5) cout << a[i] << " ";
    cout << endl;
    return 0;
}

void input(){
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
