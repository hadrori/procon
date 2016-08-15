#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n;
string s;

int solve() {
    string t = "";
    int i = 0;
    while(t.size() < s.size()) {
        if(i == 0) t = "b";
        else if(i%3 == 0) t = "b"+t+"b";
        else if(i%3 == 1) t = "a"+t+"c";
        else t = "c"+t+"a";
        i++;
    }
    if(t != s) return -1;
    return i-1;
}

void input() {
    cin >> n >> s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
