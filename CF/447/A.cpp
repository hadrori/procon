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
int p, n, used[512], x[512];

int solve(){
    rep(i,n) {
        if(used[x[i]%p]) return i+1;
        used[x[i]%p] = 1;
    }
    return -1;
}

void input(){
    cin >> p >> n;
    rep(i,n) cin >> x[i];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
