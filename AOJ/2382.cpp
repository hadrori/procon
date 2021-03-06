#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
const int MAX = 40010;

struct union_find{
    int rnk[MAX], par[MAX];
    union_find(int n){ for(int i = 0; i < n; i++) rnk[i] = 1, par[i] = i;}
    int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]);}
    void unite(int x, int y){
        if((x = find(x)) == (y = find(y))) return;
        if(rnk[x] > rnk[y]) par[y] = x;
        else{ par[x] = y; if(rnk[x] == rnk[y]) rnk[y]++;}
    }
};

int N, W, H, X[3*MAX], Y[3*MAX], wall;

int solve(){
    union_find uf(N);
    memset(X,-1,sizeof(X)); memset(Y,-1,sizeof(Y));
    wall = 0;
    rep(i,N){
        int x, y; cin >> x >> y;
        wall |= (x==W) | (x==1) | (y==H) | (y==1);
        if(X[x] < 0) X[x] = i;
        else uf.unite(i,X[x]);
        if(Y[y] < 0) Y[y] = i;
        else uf.unite(i,Y[y]);
    }
    set<int> cnt;
    rep(i,W+1) if(X[i] >= 0) cnt.insert(uf.find(X[i]));
    return N-1+(cnt.size()>1? cnt.size()-wall: 0);
}

int main(){
    cin >> N >> W >> H;
    cout << solve() << endl;
    return 0;
}
