#include <bits/stdc++.h>
using namespace std;
#define int long long
const int m = 1e9+7;
int x, y, n;

int solve(){
    if(x < 0) x+=m;
    if(y < 0) y+=m;
    n--;
    n %= 6;
    switch(n){
    case 0LL: return x;
    case 1LL: return y;
    case 2LL: return (y-x+m)%m;
    case 3LL: return (m-x)%m;
    case 4LL: return (m-y)%m;
    case 5LL: return (x-y+m)%m;
    }
    return n;
}

void input(){
    cin >> x >> y >> n;
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
