#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

void solve() {
    int ans = 0;
    repi(i,10,1000000000) {
        string s = to_string(i);
        reverse(begin(s),end(s));
        if(s[0] == '0') continue;
        int x = i + atoi(s.c_str());
        while(x) {
            if(x%2) x /= 10;
            else break;
        }
        if(!x) ans++;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
