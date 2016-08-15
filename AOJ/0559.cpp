#include <bits/stdc++.h>
using namespace std;

const int mod = 100000, mask = (1<<20)-1;
char f[32][32];
int h, w, id, dp[2][2][1<<20], ex[1<<20];
vector<int> ss[2];

#define add(x,y) { x += y; if(x >= mod) x -= mod; }
#define sub(x,y) { x += mod-y; if(x >= mod) x -= mod; }
#define mul(x,y) { x = 1LL*x*y%mod; }
#define check(s) { if(ex[s] != id) { ex[s] = id; ss[1].push_back(s); } }

void set_j(int j, int s)
{
        const int ns = (mask^(1<<j))&s;
        check(ns);
        add(dp[1][1][ns], dp[0][0][s]);
        add(dp[1][1][ns], dp[0][1][s]);
}

void set_o(int j, int s)
{
        const int ns = (mask^(1<<j))&s;
        check(ns);
        add(dp[1][0][ns], dp[0][0][s]);
        if(j) {
                check(1<<(j-1)|ns);
                add(dp[1][0][1<<(j-1)|ns], dp[0][1][s]);
        }
        else add(dp[1][0][ns], dp[0][1][s]);
}

void set_i(int j, int s)
{
        if(s>>j&1) return;
        check(s);
        add(dp[1][0][s], dp[0][0][s]);
        add(dp[1][0][s], dp[0][1][s]);
}

int solve()
{
        int ans = dp[0][0][0] = 1;
        ss[0].push_back(0);
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        if(f[i][j] == '?') mul(ans, 3);
                        id++;
                        for(int &s: ss[0]) {
                                if(f[i][j] == '?') {
                                        set_j(j,s);
                                        set_o(j,s);
                                        set_i(j,s);
                                }
                                else if(f[i][j] == 'J') set_j(j,s);
                                else if(f[i][j] == 'O') set_o(j,s);
                                else if(f[i][j] == 'I') set_i(j,s);
                        }
                        ss[0].clear();
                        memset(dp[0],0,sizeof(dp[0]));
                        swap(dp[0], dp[1]);
                        swap(ss[0], ss[1]);
                }
        }
        for(auto &s: ss[0]) {
                sub(ans, dp[0][0][s]);
                sub(ans, dp[0][1][s]);
        }
        return ans;
}

void input()
{
        scanf("%d%d", &h, &w);
        for (int i = 0; i < h; i++) scanf("%s", f[i]);
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
