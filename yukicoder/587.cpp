#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int a, b, c;

int solve() {
    return (a+b-1)/b*2/3*c >= a;
}

void input() {
    cin >> a >> b >> c;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    puts(solve()? "YES": "NO");
    return 0;
}
