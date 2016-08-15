#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int m;

string to_s(int v) { string s = to_string(v); if(v < 10) s = "0"+s; return s; }

string solve() {
    if(m < 100) return "00";
    if(m <= 5000) return to_s(m/100);
    if(m <= 30000) return to_s(50+m/1000);
    if(m <= 70000) return to_s(((m/1000)-30)/5+80);
    return "89";
}

void input() {
    cin >> m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
