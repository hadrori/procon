#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)
 
const int inf = 2e9;
struct query { int t, l, r, x; };
 
struct segtree
{
    int N;
    vector<int> dat, val;
    segtree(){}
    segtree(vector<int> s) {
        int n = s.size();
        N = 1;
        while(N < n) N <<= 1;
        dat.assign(2*N-1,inf);
        val.assign(2*N-1,-1);
        rep(i,n) dat[i+N-1] = s[i];
        for(int i = N-2; i >= 0; i--)
            dat[i] = min(dat[2*i+1], dat[2*i+2]);
    }
 
    void eval(int k) {
        if(~val[k]) {
            if(k < N-1) {
                dat[2*k+1] = val[2*k+1] = val[k];
                dat[2*k+2] = val[2*k+2] = val[k];
            }
            val[k] = -1;
        }
    }
 
    void update(int a, int b, int x) { update(a,b,x,0,0,N); }
    void update(int a, int b, int x, int k, int l, int r) {
        eval(k);
        if(r <= a or b <= l) return;
        if(a <= l and r <= b) {
            dat[k] = val[k] = x;
            return;
        }
        int m = (l+r)/2;
        update(a,b,x,k*2+1,l,m);
        update(a,b,x,k*2+2,m,r);
        dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
 
    int minimum(int a, int b) { return minimum(a,b,0,0,N); }
    int minimum(int a, int b, int k, int l, int r) {
        eval(k);
        if(r <= a or b <= l) return inf;
        if(a <= l and r <= b) return dat[k];
        int m = (l+r)/2;
        int ret = min(minimum(a, b, k*2+1, l, m), minimum(a, b, k*2+2, m, r));
        dat[k] = min(dat[2*k+1], dat[2*k+2]);
        return ret;
    }
};
 
struct segtree2
{
    int N;
    vector<int> dat;
 
    segtree2(){}
    segtree2(int n) {
        N = 1;
        while(N < n) N <<= 1;
        dat.assign(2*N-1, 0);
    }
 
    void update(int a, int b, int x) { update(a,b,x,0,0,N); }
    void update(int a, int b, int x, int k, int l, int r) {
        if(r <= a or b <= l) return;
        if(a <= l and r <= b) dat[k] = max(dat[k], x);
        else {
            int m = (l+r)/2;
            update(a,b,x,2*k+1,l,m);
            update(a,b,x,2*k+2,m,r);
        }
    }
 
    int get(int i) {
        int val = 0, j = i+N-1;
        while(j) {
            val = max(val, dat[j]);
            j /= 2;
        }
        return val;
    }
};
 
int n, m;
vector<query> qs;
vector<int> vs, seq;
set<int> itr;
map<int,int> zip;
segtree st;
segtree2 st2;
 
bool solve()
{
    sort(begin(vs),end(vs));
    vs.erase(unique(begin(vs),end(vs)),end(vs));
    m = vs.size();
    rep(i,m) {
        zip[vs[i]] = i;
        itr.insert(i);
    }
    seq.resize(m, 0);
    st2 = segtree2(m);
    for(auto &q: qs) {
        int l = zip[q.l], r = zip[q.r];
        if(!q.t) st2.update(l,r,q.x);
        else {
            auto it = itr.lower_bound(l);
            while(it != end(itr) and *it < r) {
                int v = st2.get(*it);
                seq[*it] = v? v: inf;
                itr.erase(it++);
            }
        }
    }
 
    for(auto &e: itr) seq[e] = st2.get(e);
    rep(i,m) if(!seq[i]) seq[i] = inf;
    st = segtree(seq);
 
    for(auto &q: qs) {
        int l = zip[q.l], r = zip[q.r];
        if(q.t) st.update(l,r,q.x);
        else if(st.minimum(l,r) != q.x) return 0;
    }
    return 1;
}
 
void input()
{
    scanf("%d", &n);
    int t, l, r, x;
    rep(i,n) {
        scanf("%d%d%d%d", &t, &l, &r, &x);
        qs.push_back((query){t,l,r+1,x});
        vs.push_back(l);
        vs.push_back(r);
        vs.push_back(l+1);
        vs.push_back(r+1);
    }
}
 
int main()
{
    input();
    puts(solve()? "YES": "NO");
    return 0;
}
