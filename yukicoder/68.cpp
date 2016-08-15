#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int n, k, d;
string s;

int solve() {
    k--;
    int l = k, r = k, d = 1;
    if(s[k] == '(') {
        r++;
        while(d) {
            if(s[r++] == '(') d++;
            else d--;
        }
        return r;
    }
    else {
        l--;
        while(d) {
            if(s[l--] == ')') d++;
            else d--;
        }
        return l+2;
    }
    return 0;
}

void input() {
    cin >> n >> k >> s;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
