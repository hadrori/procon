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
    void add(int a, int b, int x) { add(a,b,x,0,0,N); }
    int add(int a, int b, int x, int k, int l, int r) {
        if(b <= l or r <= a) return dat[k];
        if(a <= l and r <= b) {
            sum[k] += x;
            return dat[k] += x;
        }
        int m = (l+r)/2;
        return dat[k] = max(add(a,b,x,2*k+1,l,m),add(a,b,x,2*k+2,m,r))+sum[k];
    }
    int maximum(int a, int b) { return maximum(a,b,0,0,N); }
    int maximum(int a, int b, int k, int l, int r) {
        if(b <= l or r <= a) return 0;
        if(a <= l and r <= b) return dat[k];
        int m = (l+r)/2;
        return max(maximum(a,b,2*k+1,l,m),maximum(a,b,2*k+2,m,r))+sum[k];
    }
};

int n;
segtree st(1<<20);

void solve() {
    cout << st.maximum(0,1000001) << endl;
}

void input() {
    cin >> n;
    int a, b;
    rep(i,n) {
        cin >> a >> b;
        st.add(a,b+1,1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}
