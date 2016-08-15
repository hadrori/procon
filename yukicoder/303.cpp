#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

const int di[] = {-1,1,-2,2,-2,2,-1,1}, dj[] = {-2,-2,-1,-1,1,1,2,2};

int x, y;

int solve() {
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(0,make_pair(0,0)));
    while(!q.empty()) {
        int d = q.front().first;
        int i = q.front().second.first, j = q.front().second.second;
        q.pop();
        if(y == i and j == x) return 1;
        if(d == 3) continue;
        for (int k = 0; k < 8; k++)
            q.push(make_pair(d+1, make_pair(i+di[k], j+dj[k])));
    }
    return 0;
}

void input() {
    scanf("%d%d", &x, &y);
}

int main() {
    input();
    puts(solve()? "YES": "NO");
    return 0;
}
