#include <bits/stdc++.h>
using namespace std;
const int q[] = {2, 3, 5, 10, 12, 15}, p[] = {380, 550, 850, 1520, 1870, 2244};

int w, dp[64];

int main()
{
        for (int i = 1; i < 64; i++) dp[i] = 1e9;
        for (int i = 0; i < 6; i++)
                for (int j = 0; j < 51-q[i]; j++)
                        dp[j+q[i]] = min(dp[j+q[i]], dp[j]+p[i]);

        while(cin >> w, w) cout << dp[w/100] << endl;
        return 0;
}
