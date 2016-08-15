#include <iostream>

using namespace std;
#define repi(i,a,b) for(int (i) = int(a); (i) < int(b); i++)
#define rep(i,a) repi(i,0,a)

int n, m;
double prob[3010][310];

int main(){
    cin >> n >> m;
    rep(i,m) dp[0][i] = 1.;
    rep(i,n) rep(j,m){
        int t; cin >> t;
        prob[i][j] = t/1000.;
    }

    double ans = 0.;

    printf("%.12f\n",ans);
    return 0;
}
