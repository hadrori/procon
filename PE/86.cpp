#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int N = 1e6;

int count(int m) {
    int ret = 0;
    for(int i = 2; i <= m; i++)
        for(int j = 1+i%2; j < i; j += 2) {
            if(__gcd(i,j) != 1) continue;
            int a = i*i-j*j, b = 2*i*j;
            if(a > b) swap(a,b);
            repi(k,1,m/a+1) {
                const int x = k*a, y = k*b;
                if(y <= m) {
                    ret += x/2;
                    if(y < x*2) ret += x-(y-1)/2;
                }
                else if(x <= m and y < x*2) ret += (x*2-y+2)/2;
            }
        }
    return ret;
}

void solve() {
    assert((cout << count(100) << endl) && count(100) == 2060);
    int l = 0, r = 1, m;
    while(count(r) < N) r <<= 1;
    l = r/2;
    while(r-l>1) {
        m = (l+r)/2;
        if(count(m) <= N) l = m;
        else r = m;
    }
    cout << "answer : " << r << endl;
}

int main() {
    solve();
    return 0;
}
