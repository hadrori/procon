#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;

int k;
string s;

int solve(){
    int ans = 0; k = s.size()+k;
    rep(l,k)for(int n = 1; l+n+n <= k; n++){
        bool ok = 1;
        rep(j,n) {
            if(l+j >= (int)s.size() or l+j+n >= (int)s.size()) break;
            if(s[l+j] != s[l+j+n]) {
                ok = 0;
                break;
            }
        }
        if(ok) ans = max(ans, 2*n);
    }
    return ans;
}

void input(){
    cin >> s;
    cin >> k;
}

int main(){
    input();
    cout << solve() << endl;
    return 0;
}
