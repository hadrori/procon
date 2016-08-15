#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;

struct circle
{
        int x, y, r;
        circle(){}
        circle(int x, int y, int r) : x(x), y(y), r(r) {}
};

int n, dp[2][1024], done[1024];
circle s[2];
vector<circle> vs[2], xs[2];

inline void chmax(int &x, int y) { x = max(x,y); }
inline int sq(int x) { return x*x; }
inline int norm(const circle &a, const circle &b) { return sq(a.x-b.x)+sq(a.y-b.y); }
inline bool contain(const circle &a, const circle &b) { return sqrt(norm(a,b))+b.r < a.r-eps; }
inline bool cross(const circle &a, const circle &b) { return sqrt(norm(a,b)) < a.r+b.r+eps; }

void topo_dfs(int v, int k)
{
        if(done[v]) return;
        done[v] = 1;
        for (int i = 0; i < (int)vs[k].size(); i++)
                if(contain(vs[k][v], vs[k][i])) topo_dfs(i,k);
        xs[k].push_back(vs[k][v]);
}

int solve()
{
        for (int i = 0; i < 2; i++) {
                memset(done,0,sizeof(done));
                for (int j = 0; j < (int)vs[i].size(); j++) topo_dfs(j,i);
        }
        int ans = 0;
        memset(dp,0,sizeof(dp));
        for (int i = 0; i < 2; i++) {
                const int m = xs[i].size();
                for (int j = 0; j < m; j++) {
                        dp[i][j] = 1;
                        for (int k = 0; k < j; k++)
                                if(contain(xs[i][j], xs[i][k]))
                                        chmax(dp[i][j], dp[i][k]+1);
                        chmax(ans, dp[i][j]);
                }
        }

        for (int i = 0; i < (int)xs[0].size(); i++)
                for (int j = 0; j < (int)xs[1].size(); j++)
                        if(!cross(xs[0][i], xs[1][j])) chmax(ans, dp[0][i]+dp[1][j]);
        return ans;
}

bool input()
{
        scanf("%d", &n);
        if(!n) return 0;
        int x, y, r;
        for (int i = 0; i < 2; i++) {
                vs[i].clear();
                xs[i].clear();
                scanf("%d %d", &x, &y);
                s[i] = circle(x,y,0);
        }
        for (int i = 0; i < n; i++) {
                scanf("%d %d %d", &x, &y, &r);
                circle c(x,y,r);
                if(norm(s[0], c) < r*r and norm(s[1], c) < r*r) continue;
                if(norm(s[0], c) < r*r) vs[0].push_back(c);
                if(norm(s[1], c) < r*r) vs[1].push_back(c);
        }
        return 1;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
