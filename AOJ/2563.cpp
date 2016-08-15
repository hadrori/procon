#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int N = 100010;
int B;

template<class T> class bit {
    vector<T> dat;
    int N;
public:
    bit(){}
    bit(int N) : N(N){
        dat.assign(N,0);
    }
    T sum(int i){
        T ret = 0;
        for(--i; i>=0; i=(i&(i+1))-1) ret += dat[i];
        return ret;
    }
    T sum(int i, int j){ return sum(j) - sum(i);}
    void add(int i, T x){ for(; i < N; i|=i+1) dat[i] += x;}
};

struct query {
    int l, r, x, id;
    query(int l, int r, int x, int id) : l(l), r(r), x(x), id(id) {}
    bool operator<(const query &q) const {
        if(l/B != q.l/B) return l/B < q.l/B;
        return r > q.r;
    }
};

int n, m, q, ans[N];
vector<query> as, qs;
vector<int> xs;
unordered_map<int,int> zip;
vector<vector<int>> add, sub;

void compress() {
    xs.clear();
    for(auto &e: as) {
        xs.push_back(e.l);
        xs.push_back(e.r-1);
        xs.push_back(e.r);
    }
    for(auto &e: qs) {
        xs.push_back(e.l);
        xs.push_back(e.r-1);
        xs.push_back(e.r);
    }
    sort(begin(xs),end(xs));
    xs.erase(unique(begin(xs),end(xs)), end(xs));
    rep(i,xs.size()) zip[xs[i]] = i;
}

void solve() {
    compress();
    B = sqrt(m);

}

void input() {
    scanf("%d%d%d", &n, &m, &q);
    int l, r, x;
    rep(i,m) {
        scanf("%d%d%d", &l, &r, &x);
        l--;
        as.emplace_back(l,r,x,i);
    }
    rep(i,q) {
        scanf("%d%d%d", &l, &r, &x);
        l--;
        qs.emplace_back(l,r,x,i);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
