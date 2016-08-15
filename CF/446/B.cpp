#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int inf = 1LL<<63;

int r, c, k, p, a, rs[1024], cs[1024];
int rsum[1000010], csum[1000010];

void calc(){
    priority_queue<int> rq, cq;
    rep(i,r) rq.push(rs[i]);
    rep(i,k) {
        int val = rq.top(); rq.pop();
        rsum[i+1] = rsum[i]+val;
        rq.push(val-p*c);
    }
    rep(i,c) cq.push(cs[i]);
    rep(i,k) {
        int val = cq.top(); cq.pop();
        csum[i+1] = csum[i]+val;
        cq.push(val-p*r);
    }
}

int solve(){
    int ans = -inf;
    calc();
    rep(i,k+1) ans = max(ans, rsum[i]+csum[k-i]-p*i*(k-i));
    return ans;
}

void input(){
    scanf("%I64d%I64d%I64d%I64d", &r, &c, &k, &p);
    rep(i,r) rep(j,c){
        scanf("%I64d", &a);
        rs[i] += a;
        cs[j] += a;
    }
}

signed main(){
    input();
    printf("%I64d\n", solve());
    return 0;
}
