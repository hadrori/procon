#include <bits/stdc++.h>
using namespace std;

int n, k, cs[512][1024], seq[1024];

void solve()
{
        while(1) {
                for (int i = 0; i < n; i++) seq[i] = rand()%2;
                bool ok = 1;
                for (int i = 0; i < k; i++) {
                        int sum = 0;
                        for (int j = 0; j < n/2; j++) {
                                sum += seq[cs[i][j]];
                                if(3*n/8 < sum) break;
                        }
                        if(sum < n/8 or 3*n/8 < sum) {
                                ok = 0;
                                break;
                        }
                }
                if(ok) {
                        for (int i = 0; i < n; i++) printf("%d", seq[i]);
                        puts("");
                        break;
                }
        }
}

void input()
{
        scanf("%d %d", &n, &k);
        for (int i = 0; i < k; i++)
                for (int j = 0; j < n/2; j++) {
                        scanf("%d", cs[i]+j);
                        cs[i][j]--;
                }
}

int main()
{
        input();
        solve();
        return 0;
}
