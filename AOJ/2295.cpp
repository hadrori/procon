#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
int N, a[128];

bool cmp(int u, int v){
    if(u < 2 or v < 2) return u > v;
    return u < v;
}

void solve(){
    sort(a,a+N,cmp);
    int e = 1;
    for(int i = N-1; i >= 0; i--){
        if(!a[i]) e ^= 1;
        else if(a[i] == 1) e = 1;
        if(e==0 and a[i] > 1 and i > 0)
            swap(a[i], a[i-1]);
        else if(i > 0 and a[i] == 3 and a[i-1] == 2)
            swap(a[i], a[i-1]);
        if(a[i]>1) break;
    }
    rep(i,N) cout << a[i] << endl;
}

void input(){
    cin >> N;
    rep(i,N) cin >> a[i];
}
int main(){
    input();
    solve();
    return 0;
}


