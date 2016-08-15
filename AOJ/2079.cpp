#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const string dir = "LUDR";
int n;
string s;

bool valid(int p, int q) { // left right
    if(p == 2) return q == 1 or q > p;
    return q > p;
}

int sim(int l) {
    int p[] = {-1,5};
    rep(i,n) {
        p[l] = dir.find(s[i]);
        if(!valid(p[0], p[1])) return 0;
        l = 1-l;
    }
    return 1;
}

int solve() {
    n = s.size();
    return sim(0) or sim(1);
}

void input() {
    cin >> s;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    int t; cin >> t;
    while(t--) {
        input();
        cout << (solve()?"Yes":"No") << endl;
    }
    return 0;
}
