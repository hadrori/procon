#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

double p, q;

int solve() {
    double p1 = (1-p)*(1-q)*q, p2 = p*(1-q)*(1-q)*q;
    return p1 < p2;
}

void input() {
    scanf("%lf %lf", &p, &q);
}

int main() {
    input();
    puts(solve()? "YES": "NO");
    return 0;
}
