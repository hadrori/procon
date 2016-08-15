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

int n;

void solve(){
    rep(i,n/2){
        rep(j,(n-2*i-1)/2) cout << "*";
        rep(j,2*i+1) cout << "D";
        rep(j,(n-2*i-1)/2) cout << "*";        
        cout << endl;
    }
    rep(i,n) cout << "D";
    cout << endl;
    rep(ii,n/2){
        int i = n/2-ii-1;
        rep(j,(n-2*i-1)/2) cout << "*";
        rep(j,2*i+1) cout << "D";
        rep(j,(n-2*i-1)/2) cout << "*";        
        cout << endl;
    }
}

void input(){
    cin >> n;
}

int main(){
    cin.sync_with_stdio(0);
    input();
    solve();
    return 0;
}
