#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int a[] = {2,3,5,7,11,13}, b[] = {4,6,8,9,10,12};
int c[200], k;

double solve() {
    rep(i,6) rep(j,6) c[a[i]*b[j]]++;
    return 1.*c[k]/36;
}

void input() {
    cin >> k;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
