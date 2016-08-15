#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n;
double dp[1<<20];

double solve() {
    double a = (1000000-n*100)*0.01, b = n*100*0.99;
    return a/(a+b)*100;
}

void input() {
    scanf("%d", &n);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
