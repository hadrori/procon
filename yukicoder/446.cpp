#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

set<int> s;
int n;

int solve() {
    int a, b;
    rep(i,n) {
        cin >> a >> b;
        s.insert(b-a);
    }
    if(s.size() != 1 or *begin(s) <= 0) return -1;
    return *begin(s);
}

void input() {
    cin >> n;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
