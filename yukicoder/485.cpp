#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, a[100010];

int solve() {
    sort(a,a+n);
    int l = 0, r = 0, ans = 0;
    while(l < n) {
        while(r < n and a[r] == a[l]) r++;
        if(r-l == 1) ans++;
        l = r;
    }
    return ans;
}

void input() {
    scanf("%d", &n);
    rep(i,n) scanf("%d", a+i);
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}
