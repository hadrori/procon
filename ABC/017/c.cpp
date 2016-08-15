#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

struct segtree {
    int N;
    vector<i64> dat, sum;
    segtree(){}
    segtree(int n) {
        N = 1;
        while(N < n) N <<= 1;
        dat.assign(2*N-1,0);
        sum.assign(2*N-1,0);
    }
    void add(int a, int b, i64 x) { add(a,b,x,0,0,N); }
    i64 add(int a, int b, i64 x, int k, int l, int r) {
        if(b <= l or r <= a) return dat[k];
        if(a <= l and r <= b) {
            sum[k] += x;
            return dat[k] += x*(r-l);
        }
        eval(k,l,r);
        int m = (l+r)/2;
        return dat[k] = add(a,b,x,2*k+1,l,m)+add(a,b,x,2*k+2,m,r);
    }
    i64 summation(int a, int b) { return summation(a,b,0,0,N); }
    i64 summation(int a, int b, int k, int l, int r) {
        if(b <= l or r <= a) return 0;
        if(a <= l and r <= b) return dat[k];
        eval(k,l,r);
        int m = (l+r)/2;
        return summation(a,b,2*k+1,l,m)+summation(a,b,2*k+2,m,r);
    }

    void eval(int k, int l, int r) {
        dat[k] += sum[k]*(r-l);
        int lk = 2*k+1, rk = 2*k+2;
        if(r-l != 1) {
            sum[lk] += sum[k];
            dat[lk] += (r-l)/2*sum[k];
            sum[rk] += sum[k];
            dat[rk] += (r-l)/2*sum[k];
        }
        sum[k] = 0;
    }
};

int n, m, l[100010], r[100010], s[100010];
segtree st;

void solve() {
    i64 ans = 0, sum = accumulate(s,s+n,0);
    st = segtree(m);
    rep(i,n) st.add(l[i],r[i],s[i]);
    rep(i,m) ans = max(ans, sum-st.summation(i,i+1));
    cout << ans << endl;
}

void input() {
    cin >> n >> m;
    rep(i,n) cin >> l[i] >> r[i] >> s[i];
    rep(i,n) l[i]--;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
