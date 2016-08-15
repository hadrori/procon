#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
const string y = "YES", n = "NO";
int N, c[32], cnt[32], used[32];

string solve(){
    if(N==1) return y;
    if(cnt[N] != 1 or cnt[2] or
       cnt[1] <= N/2 or N <= cnt[1]) return n;
    sort(c,c+N);
    reverse(c,c+N);
    prepare();
    return n;
}

void input(){
    cin >> N;
    rep(i,N){
        cin >> c[i];
        cnt[c[i]]++;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}

