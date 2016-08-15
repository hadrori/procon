#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int a[8], c[16];

string solve() {
    set<int> s;
    rep(i,5) s.insert(a[i]), c[a[i]]++;
    if(s.size() == 4) return "ONE PAIR";
    else if(s.size() == 3) {
        rep(i,14) if(c[i] == 3) return "THREE CARD";
        return "TWO PAIR";
    }
    else if(s.size() == 2) rep(i,14) if(c[i] == 3) return "FULL HOUSE";
    return "NO HAND";
}

void input() {
    rep(i,5) scanf("%d", a+i);
}

int main() {
    input();
    cout << solve() << endl;
    return 0;
}
