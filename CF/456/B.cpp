#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;
string n;
int m;

int solve(){
    if(n.size() == 1) n = "0"+n;
    m = ((int)(n[(int)n.size()-1]-'0')+(int)(n[n.size()-2]-'0')*10)%4;
    return m? 0: 4;
}

void input(){
    cin >> n;
}

int main(){
    cin.sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
