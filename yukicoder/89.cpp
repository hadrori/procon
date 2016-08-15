#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n;

int solve() {
    return 32-__builtin_clz(n)-(__builtin_popcount(n)==1? 1: 0);
}

void input() {
    scanf("%d", &n);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
