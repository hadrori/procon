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
const string Y = "Happy", N = "Poor";
typedef pair<int,int> pii;

int n, c, d, ok;

string solve(){
    return ok? Y: N;
}

void input(){
    scanf("%d", &n);
    rep(i,n){
        scanf("%d%d", &c, &d);
        if(c < d) ok = 1;
    }
}

int main(){
    cin.sync_with_stdio(0);
    input();
    cout << solve() << " Alex" << endl;
    return 0;
}
