#include <bits/stdc++.h>
using namespace std;

int n, s, memo[16][512];

int solve()
{
        if(n > 10 or s > 385) return 0;
        return memo[n][s];
}

int used[10];
void dfs(int sum, int d)
{
        memo[d][sum]++;
        if(d == 10) return;
        for (int i = 0; i < 10; i++) {
                if(used[i]) continue;
                used[i] = 1;
                dfs(sum+i*(d+1), d+1);
                used[i] = 0;
        }
}

int main()
{
        dfs(0,0);
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        while(cin >> n >> s) cout << solve() << endl;
        return 0;
}
