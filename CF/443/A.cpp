#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;

string s;

int solve(){
    set<char> S;
    for(int i = 1; i < s.size()-1; i+=3)
        S.insert(s[i]);
    return S.size();
}

int main(){
    getline(cin,s);
    cout << solve() << endl;
    return 0;
}
