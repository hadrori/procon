#include <bits/stdc++.h>
using namespace std;

struct union_find
{
        vector<int> rnk, par;
        union_find(){}
        union_find(int n){
                rnk.assign(n,1);
                par.assign(n,0);
                for(int i = 0; i < n; i++) par[i] = i;
        }        
        
        int find(int x) {
                if(x == par[x]) return x;
                else return par[x] = find(par[x]);
        }
        void unite(int x, int y) {
                x = find(x); y = find(y);
                if(x == y) return;
                if(rnk[x] > rnk[y]) par[y] = x;
                else {
                        par[x] = y;
                        if(rnk[x] == rnk[y]) rnk[y]++;
                }
        }
        bool same(int x, int y) {
                x = find(x); y = find(y);
                return x == y;
        }
};

struct query { int u, v, q; };

const int B = 200;
int n, m;
vector<query> qs;
union_find uf;


void solve()
{
}

void input()
{
        scanf("%d %d", &n, &m);
        int q, u, v;
        for (int i = 0; i < m; i++) {
                scanf("%d %d %d", &q, &u, &v);
                qs.push_back((query){u,v,q});
        }
}

int main()
{
        input();
        solve();
        return 0;
}
