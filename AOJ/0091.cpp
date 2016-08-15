#include <bits/stdc++.h>
using namespace std;
const int di[] = {0,-1,0,1,0,-1,1,1,-1,-2,0,2,0}, dj[] = {0,0,1,0,-1,1,1,-1,-1,0,2,0,-2};
const int dik[] = {0,1,1,2}, djk[] = {0,0,1,0};
struct point { int i, j, k;};

int f[10][10], n, sum;
vector<point> ans;

bool ok(int i, int j, int k)
{
        int l = (k-1)/2;
        if(i < 1+l or i > 8-l or j < 1+l or j > 8-l) return 0;
        for (int a = 0; a <= 4*k; a++) if(!f[i+di[a]][j+dj[a]]) return 0;
        return 1;
}

void add(int i, int j, int k, int x)
{
        for (int a = 0; a <= 4*k; a++) f[i+di[a]][j+dj[a]] += x, sum += x;
}

bool dfs(int i, int j, int res)
{
        if(res == 0) return sum == 0;
        if(j == 10) return dfs(i+1,0,res);
        if(i == 10) return 0;
        if(!f[i][j]) return dfs(i,j+1,res);
        for(int k = 3; k > 0; k--) {
                int ni = i+dik[k], nj = j+djk[k];
                if(ok(ni,nj,k)){
                        add(ni,nj,k,-1);
                        if(dfs(i,j,res-1)) {
                                ans.push_back((point){ni,nj,k});
                                return 1;
                        }
                        add(ni,nj,k,1);
                }
        }
        return dfs(i,j+1,res);
}

void solve()
{
        dfs(0,0,n);
        for(auto &e: ans) cout << e.j << " " << e.i << " " << e.k << endl;
}

void input()
{
        cin >> n;
        sum = 0;
        for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        cin >> f[i][j];
                        sum += f[i][j];
                }
        }
}

int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        input();
        solve();
        return 0;
}
