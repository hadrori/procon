#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

struct segtree {
    int N;
    vector<int> dat, sum;
    segtree(){}
    segtree(int n) {
        N = 1;
        while(N < n) N <<= 1;
        dat.assign(2*N-1,0);
        sum.assign(2*N-1,0);
    }
    void add(int a, int b) { add(a,b,0,0,N); }
    int add(int a, int b, int k, int l, int r) {
        if(b <= l or r <= a) return dat[k];
        if(a <= l and r <= b) return lazy(k,l,r);
        eval(k,l,r);
        int m = (l+r)/2;
        return dat[k] = add(a,b,2*k+1,l,m)+add(a,b,2*k+2,m,r);
    }
    int summation(int a, int b) { return summation(a,b,0,0,N); }
    int summation(int a, int b, int k, int l, int r) {
        if(b <= l or r <= a) return 0;
        if(a <= l and r <= b) return dat[k];
        eval(k,l,r);
        int m = (l+r)/2;
        return summation(a,b,2*k+1,l,m)+summation(a,b,2*k+2,m,r);
    }

    int lazy(int k, int l, int r) {
        sum[k] = 1;
        return dat[k] = r-l;
    }

    void eval(int k, int l, int r) {
        if(!sum[k]) return ;
        dat[k] = r-l;
        if(r-l != 1) {
            lazy(2*k+1,l,(l+r)/2);
            lazy(2*k+2,(l+r)/2,r);
        }
        sum[k] = 0;
    }
};

int h, w, d;
string s[512];
segtree sts[512];

int solve() {
    d--;
    rep(i,h) sts[i] = segtree(w);
    rep(i,h) rep(j,w) if(s[i][j] == 'x') {
        rep(k,d+1) {
            int e = d-k;
            if(i-k >= 0) sts[i-k].add(max(0,j-e),min(w,j+e+1));
            if(i+k < h) sts[i+k].add(max(0,j-e),min(w,j+e+1));
        }
    }
    int ans = 0, l = d, r = w-d;
    if(r-l <= 0) return 0;
    repi(i,d,h-d) ans += r-l-sts[i].summation(l,r);
    return ans;
}

void input() {
    cin >> h >> w >> d;
    rep(i,h) cin >> s[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
