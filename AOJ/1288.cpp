#include <bits/stdc++.h>
using namespace std;
/*
  0: 2 2 2 2
  1: 0
  2: 1 1 2 2 2
  3: 1 1 1 2
  4: 0 1 2
  5: 1 1 2 2 2
  6: 1 2 2 2 2
  7: 1 1 2
  8: 2 2 2 2 2
  9: 1 2 2 2
 */
const vector<int> f[] = {{2,2,2,2}, {0}, {1,1,2,2,2}, {1,1,1,2}, {0,1,2},
                         {1,1,2,2,2}, {1,2,2,2,2}, {1,1,2}, {2,2,2,2,2}, {1,2,2,2}};
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

int n, m, x[1024][2], y[1024][2], c[10], cnt[1024], id[1024];

bool touch(int cx, int cy, int i)
{
        const int dx1 = cx-x[i][0], dy1 = cy-y[i][0];
        const int dx2 = x[i][1]-cx, dy2 = y[i][1]-cy;
        return dy1*dx2 == dy2*dx1 and
               ((dx1 <= 0 and dx2 <= 0) or (dx1 >= 0 and dx2 >= 0)) and
               ((dy1 <= 0 and dy2 <= 0) or (dy1 >= 0 and dy2 >= 0));
}

inline int cross(const complex<int> &a, const complex<int> &b) { return imag(conj(a)*b); }
int ccw(int i, int j)
{
        complex<int> p(x[i][0], y[i][0]), q(x[i][1], y[i][1]), r(x[j][0], y[j][0]), s(x[j][1], y[j][1]);
        complex<int> b, c;
        if(p == r) { // q - p - s
                b = p-q;
                c = s-q;
        }
        else if(p == s) { // q - p - r
                b = p-q;
                c = r-q;
        }
        else if(q == r) { // p - q - s
                b = q-p;
                c = s-p;
        }
        else if(q == s) { // p - q - r
                b = q-p;
                c = r-p;
        }
        else assert(0);
        if(cross(b,c) > 0) return 1;
        if(cross(b,c) < 0) return -1;
        return 0;
}

void solve()
{
        m = 0;
        memset(cnt,0,sizeof(cnt));
        memset(c,0,sizeof(c));
        memset(id,-1,sizeof(id));
        union_find uf(n);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if(i == j) continue;
                        for (int k = 0; k < 2; k++) {
                                if(touch(x[i][k], y[i][k], j)) {
                                        uf.unite(i,j);
                                        cnt[i]++;
                                }
                        }
                }
        }
        vector<int> seq[1024], num[1024];
        for (int i = 0; i < n; i++) {
                const int k = uf.find(i);
                if(!~id[k]) id[k] = m++;
                seq[id[k]].push_back(cnt[i]);
                num[id[k]].push_back(i);
        }
        for (int i = 0; i < m; i++) {
                sort(begin(seq[i]),end(seq[i]));
                bool tf = 0;
                for (int j = 0; j < 10; j++) {
                        if(seq[i] == f[j]) {
                                if(j == 2) tf = 1;
                                else c[j]++;
                                break;
                        }
                }
                if(tf) {
                        int v = -1;
                        for (int j = 0; j < 5; j++) {
                                if(cnt[num[i][j]] == 1) {
                                        v = j;
                                        break;
                                }
                        }
                        int w = -1;
                        for (int j = 0; j < 5; j++) {
                                if(j == v) continue;
                                for (int k = 0; k < 2; k++) {
                                        if(touch(x[num[i][v]][k], y[num[i][v]][k], num[i][j])) {
                                                if(ccw(num[i][v], num[i][j]) == 1) w = 0;
                                                else w = 1;
                                                break;
                                        }
                                }
                                if(~w) break;
                        }
                        if(w) c[2]++;
                        else c[5]++;
                }
        }

        for (int i = 0; i < 10; i++) printf("%d%c", c[i], i==9? '\n': ' ');
}

bool input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
                scanf("%d %d %d %d", x[i], y[i], x[i]+1, y[i]+1);
        return n;
}

int main()
{
        while(input()) solve();
        return 0;
}
