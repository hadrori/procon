#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;

string s;
int k, w[32], v;

int solve(){
    int ret = 0;
    rep(i,s.size())
        ret += (i+1)*w[s[i]-'a'];
    rep(i,k) ret += (i+s.size()+1)*v;
    return ret;
}

void input(){
    cin >> s;
    cin >> k;
    rep(i,26) cin >> w[i], v = max(v,w[i]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
