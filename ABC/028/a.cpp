#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const string s[] = {"Bad", "Good", "Great", "Perfect"};
const int a[] = {60,90,100,101};
int n;

string solve() {
    return s[upper_bound(a,a+4,n)-a];
}

void input() {
    cin >> n;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
