#include <bits/stdc++.h>
using namespace std;
const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

int w, h, n, si, sj, ti, tj, wall[64][64][4], dist[64][64];
inline bool in(int i, int j) { return 0 <= i and i < h and 0 <= j and j < w;}

int calc()
{
        memset(dist,-1,sizeof(dist));
        queue<pair<int,int>> q;
        q.push(pair<int,int>(si,sj));
        dist[si][sj] = 0;
        while(!q.empty()) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for (int d = 0; d < 4; d++) {
                        const int ni = i+di[d], nj = j+dj[d];
                        if(!in(ni,nj) or wall[i][j][d] or ~dist[ni][nj]) continue;
                        dist[ni][nj] = dist[i][j]+1;
                        if(ni == ti and nj == tj) return dist[ti][tj];
                        q.push(pair<int,int>(ni,nj));
                }

        }
        return -1;
}

int solve()
{
        int ans = 0, m = calc();
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        for (int d = 0; d < 4; d++) {
                                if(!wall[i][j][d]) {
                                        wall[i][j][d] = 1;
                                        ans = max(ans, calc()-m);
                                        wall[i][j][d] = 0;
                                }
                        }
                }
        }
        return ans;
}

void input()
{
        scanf("%d%d%d", &w, &h, &n);
        for (int _ = 0; _ < n; _++) {
                int ai, aj, bi, bj;
                scanf("%d%d%d%d", &aj, &ai, &bj, &bi);
                if(aj == bj) {
                        if(ai > bi) swap(ai, bi);
                        for (int i = ai; i < bi; i++) {
                                if(aj) wall[i][aj-1][0] = 1;
                                wall[i][aj][2] = 1;
                        }
                }
                if(ai == bi) {
                        if(aj > bj) swap(aj, bj);
                        for (int j = aj; j < bj; j++) {
                                if(ai) wall[ai-1][j][1] = 1;
                                wall[ai][j][3] = 1;
                        }
                }
        }
        scanf("%d%d%d%d", &sj, &si, &tj, &ti);
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
