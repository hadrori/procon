#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

inline int distance(int x, int y, int a, int b) { return abs(x-a)+abs(y-b); }
inline void chmax(i64 &x, i64 y) { x = max(x,y); }
inline void chmin(i64 &x, i64 y) { x = min(x,y); }

int n, m, w, t;
map<string, int> id;
int val[8], wei[8], x[8], y[8];
vector<pair<int,int>> item[8];
i64 dist[1<<7], bene[1<<7], dp[10010];

i64 solve()
{
        for (int i = 0; i < (1<<n); i++) {
                vector<int> cs;
                for (int j = 0; j < n; j++) if(i>>j&1) cs.push_back(j);
                dist[i] = 1234567890LL;
                do {
                        int px = 0, py = 0, sum = 0;
                        for(auto &e: cs) {
                                sum += distance(px,py,x[e],y[e]);
                                px = x[e]; py = y[e];
                        }
                        sum += distance(px,py,0,0);
                        chmin(dist[i], sum);
                } while(next_permutation(begin(cs),end(cs)));
                memset(dp,0,sizeof(dp));
                for (int &j: cs)
                        for(auto &p: item[j])
                                for (int k = 0; k <= w-p.first; k++)
                                        chmax(dp[k+p.first], dp[k]+p.second);
                bene[i] = dp[w];
        }
        memset(dp,0,sizeof(dp));
        for (int i = 0; i < (1<<n); i++)
                for (int j = 0; j <= t-dist[i]; j++)
                        chmax(dp[j+dist[i]], dp[j]+bene[i]);
        return dp[t];
}

void input()
{
        scanf("%d%d%d%d", &n, &m, &w, &t);
        char s[32];
        for (int i = 0; i < m; i++) {
                scanf("%s %d %d", s, wei+i, val+i);
                id[s] = i;
        }
        for (int i = 0; i < n; i++) {
                int a, b;
                scanf("%d%d%d", &a, x+i, y+i);
                for (int j = 0; j < a; j++) {
                        scanf("%s %d", s, &b);
                        item[i].push_back(make_pair(wei[id[s]], val[id[s]]-b));
                }
        }
}

int main()
{
        input();
        printf("%lld\n", solve());
        return 0;
}
