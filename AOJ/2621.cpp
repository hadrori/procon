#include <bits/stdc++.h>
using namespace std;

int n;
map<pair<int,int>, int> ps;

int solve()
{
        int ans = 0;
        for(auto &e: ps) {
                int x = e.first.first, y = e.first.second, sum = e.second;
                if(ps.count(make_pair(x+1,y))) sum += ps[make_pair(x+1,y)];
                if(ps.count(make_pair(x,y+1))) sum += ps[make_pair(x,y+1)];
                if(ps.count(make_pair(x+1,y+1))) sum += ps[make_pair(x+1,y+1)];
                ans = max(ans, sum);
                sum = e.second;
                if(ps.count(make_pair(x+1,y))) sum += ps[make_pair(x+1,y)];
                if(ps.count(make_pair(x,y-1))) sum += ps[make_pair(x,y-1)];
                if(ps.count(make_pair(x+1,y-1))) sum += ps[make_pair(x+1,y-1)];
                ans = max(ans, sum);
                sum = e.second;
                if(ps.count(make_pair(x-1,y))) sum += ps[make_pair(x-1,y)];
                if(ps.count(make_pair(x,y-1))) sum += ps[make_pair(x,y-1)];
                if(ps.count(make_pair(x-1,y-1))) sum += ps[make_pair(x-1,y-1)];
                ans = max(ans, sum);
                sum = e.second;
                if(ps.count(make_pair(x-1,y))) sum += ps[make_pair(x-1,y)];
                if(ps.count(make_pair(x,y+1))) sum += ps[make_pair(x,y+1)];
                if(ps.count(make_pair(x-1,y+1))) sum += ps[make_pair(x-1,y+1)];
                ans = max(ans, sum);
        }
        return ans;
}

void input()
{
        scanf("%d", &n);
        int x, y, w;
        for (int i = 0; i < n; i++) {
                scanf("%d%d%d", &x, &y, &w);
                ps[make_pair(x,y)] = w;
        }
}

int main()
{
        input();
        printf("%d / 1\n", solve());
        return 0;
}
