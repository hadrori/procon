#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int solve() {
    int ans = 0;
    repi(i,1,13) repi(j,1,m[i]+1) ans += i == (j/10+j%10);
    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}
