#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

ostream &operator<<(ostream &o, const pair<string,int> &p) { o << p.first << ' ' << p.second; return o; }

const string dir[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
const int sep[] = {112, 337, 562, 787, 1012, 1237, 1462, 1687, 1912, 2137, 2362, 2587, 2812, 3037, 3262, 3487, 3600};
const int pw[] = {14, 92, 200, 326, 476, 644, 830, 1028, 1244, 1466, 1706, 1958, 12000};

int a, b;

string f() { return dir[lower_bound(sep,sep+17,a)-sep]; }
int g() { return lower_bound(pw, pw+13, b)-pw; }

pair<string,int> solve() {
    if(!g()) return make_pair("C", 0);
    return make_pair(f(), g());
}

void input() {
    cin >> a >> b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
