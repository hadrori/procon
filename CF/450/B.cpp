#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 1e9+7;
int x, y, n;

int solve(){
    if(x < 0) x+=m;
    if(y < 0) y+=m;
    n--;
    n = n%6;
    if(n== 0) return x;
    if(n== 1) return y;
    if(n== 2) return (y-x+m)%m;
    if(n== 3) return (m-x)%m;
    if(n== 4) return (m-y)%m;
    return (x-y+m)%m;
}

void input(){
    cin >> x >> y >> n;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
