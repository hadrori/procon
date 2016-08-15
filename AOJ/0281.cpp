#include <bits/stdc++.h>
using namespace std;

const int d[][3] = {{1,1,1},{2,1,0},{3,0,0}};
int p[3];

int solve()
{
        int ans = 0;
        for (int i = 0; i < 3; i++) {
                int pr = p[0]/d[i][0];
                for (int j = 0; j < 3; j++) {
                        if(!d[i][j]) continue;
                        pr = min(pr, p[j]/d[i][j]);
                }
                ans += pr;
                for (int j = 0; j < 3; j++) p[j] -= pr*d[i][j];
        }
        return ans;
}


int main()
{
        int t; scanf("%d", &t);
        while(t--) {
                scanf("%d%d%d", p, p+1, p+2);
                printf("%d\n", solve());
        }
        return 0;
}
