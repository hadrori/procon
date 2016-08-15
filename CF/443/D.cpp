#include <bits/stdc++.h>
using namespace std;
#define double long double
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;

int n;
double p[128];

double solve(){
    sort(p,p+n);
    double sum, ans = 0.;
    rep(l,n)repi(r,l+1,n+1){
        sum = 0.;
        repi(i,l,r){
            double prd = p[i];
            repi(j,l,r) if(i != j) prd *= (1-p[j]);
            sum += prd;
        }
        ans = max(ans, sum);
    }
    return ans;
}

void input(){
    cin >> n;
    rep(i,n) cin >> p[i];
}

int main(){
    input();
    cout << setprecision(10);
    cout << solve() << endl;
    return 0;
}
