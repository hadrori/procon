#include <bits/stdc++.h>
using namespace std;

inline void chmax(int &x, int y) { x = max(x, y); }
int h, w, dp[2][1<<16], pos[1<<16];
string s[128];

int solve()
{
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        int ci = 0, ni = 1;
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        memset(dp[ni],-1,sizeof(dp[ni]));
                        for (int k = 0; k < 1<<w; k++) {
                                if(dp[ci][k] < 0) continue;
                                const int &p = pos[((1<<j)-1)&k];
                                if(p < (int)s[i].size()) {
                                        // put
                                        int pt = 0;
                                        if(j and (k>>(j-1)&1) and s[i][p-1] == s[i][p]) pt += 2;
                                        if(i and (k>>j&1)) {
                                                const int &q = (int)s[i-1].size()-pos[~((1<<j)-1)&k];
                                                if(q >= 0 and s[i-1][q] == s[i][p]) pt += 2;
                                        }
                                        chmax(dp[ni][1<<j|k], dp[ci][k]+pt);
                                }
                                // not put
                                if(p+w-j > (int)s[i].size()) chmax(dp[ni][~(1<<j)&k], dp[ci][k]);
                        }
                        swap(ci,ni);
                }
        }
        return *max_element(dp[h*w%2], dp[h*w%2]+(1<<w));
}

void input()
{
        cin >> h >> w;
        for (int i = 0; i < h; i++) cin >> s[i];
}

int main()
{
        input();
        for (int i = 0; i < 1<<w; i++) pos[i] = __builtin_popcount(i);
        cout << solve() << endl;
        return 0;
}
