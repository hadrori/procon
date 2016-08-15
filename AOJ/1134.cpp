#include <bits/stdc++.h>
using namespace std;

struct union_find
{
        vector<int> rnk, par;
        
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

char buf[64];
int n, m, l, wf[256][256], col[256], fwf[256][256];
map<string,int> id;

void paint(int v, int c)
{
        if(col[v]) return;
        col[v] = c;
        for (int i = 0; i < l; i++) if(fwf[v][i]) paint(i,c^3);
}

void solve()
{
        for (int i = 0; i < l; i++) paint(i,1);
        memset(fwf,0,sizeof(fwf));
        for (int i = 0; i < l; i++) {
                for (int j = i+1; j < l; j++) {
                        bool ex = 0, fx = 0;
                        for (int k = 0; k < l; k++) {
                                if((wf[i][k] or wf[k][i]) and (wf[j][k] or wf[k][j])) ex = 1;
                                if((wf[k][i] and wf[j][k]) or (wf[i][k] and wf[k][j])) fx = 1;
                        }
                        if(ex & !fx) wf[i][j] = wf[j][i] = 1;
                }
        }

        for (int k = 0; k < l; k++)
                for (int i = 0; i < l; i++)
                        for (int j = 0; j < l; j++)
                                wf[i][j] |= wf[i][k]&wf[k][j];
        printf("%d\n", l);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
                scanf("%s", buf);
                string s(buf);
                auto p = s.find('-');
                string x = s.substr(0,p), y = s.substr(p+1);
                int f = 0;
                if(id.count(x) and id.count(y)) {
                        int a = id[x], b = id[y];
                        if(col[a] != col[b] and wf[a][b]) f = 1;
                }
                puts(f? "YES": "NO");
        }
}

void init()
{
        memset(wf,0,sizeof(wf));
        memset(col,0,sizeof(col));
        id.clear();
        l = 0;
}

bool input()
{
        scanf("%d", &n);
        init();
        for (int i = 0; i < n; i++) {
                scanf("%s", buf);
                string s(buf);
                auto p = s.find('-');
                string x = s.substr(0,p), y = s.substr(p+1);
                if(!id.count(x)) id[x] = l++;
                if(!id.count(y)) id[y] = l++;
                int a = id[x], b = id[y];
                wf[a][b] = 1;
                fwf[a][b] = fwf[b][a] = 1;
        }
        return n;
}

int main()
{
        while(input()) solve();
        return 0;
}
