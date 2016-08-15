#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
typedef long long ll;
int n, m, k;
vector<int> divn, divm;

void calc(){
    repi(i,1,max(int(sqrt(n))+1, int(sqrt(m))+1)){
        if(n%i==0) divn.pb(i), divn.pb(n/i);
        if(m%i==0) divm.pb(i), divm.pb(m/i);
    }
    sort(all(divn));
    sort(all(divm));
}

ll solve(){
    if(n-1+m-1<k) return -1LL;
    calc();
    ll ans = -1;
    rep(_,2){
        for(int &x: divn){
            if(x-1 > k) break;
            if(k-x > m) continue;
            ans = max(ans, 1LL*(n/x)*(m/(k-x+2)));
        }
        swap(n,m);
        swap(divn,divm);
    }
    return ans;
}

void input(){
    cin >> n >> m >> k;
}

int main(){
    input();
    cout << solve() << endl;
    return 0;
}
