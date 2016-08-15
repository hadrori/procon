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
const int d[] = {1,-1};
int n, a[100010], b[100010], idx, v[2], done;
map<int,int> zip;

void solve(){
    int l = n, r = 0;
    sort(b,b+n);
    rep(i,n) zip[b[i]] = i;
    rep(i,n) if(zip[a[i]] != i) {
        l = i;
        break;
    }
    rep(i,n) if(zip[a[n-i-1]] != n-i-1){
        r = n-i-1;
        break;
    }
    if(l < r) reverse(a+l,a+r+1);
    else{
        puts("yes");
        cout << 1 << " " << 1 << endl;
        return;
    }
    rep(i,n) if(zip[a[i]] != i) {
        puts("no");
        return;
    }
    puts("yes");
    cout << l+1 << " " << r+1<< endl;
}

void input(){
    scanf("%d", &n);
    rep(i,n) scanf("%d", a+i), b[i] = a[i];
}

int main(){
    input();
    solve();
    return 0;
}
