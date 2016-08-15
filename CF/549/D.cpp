#include <bits/stdc++.h>
using namespace std;

int h, w;
string f[128];

int solve()
{
        int ans = 0;
        for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                        if(i == h-1 and j == w-1) ans++;
                        else if(i == h-1 and f[i][j] != f[i][j+1]) ans++;
                        else if(j == w-1 and f[i][j] != f[i+1][j]) ans++;
                        else if(f[i][j] != f[i+1][j] and f[i][j] != f[i][j+1]) ans++;
                        else if(f[i][j] != f[i+1][j+1] and f[i][j] == f[i+1][j] and f[i][j] == f[i][j+1]) ans++;
                        else if(f[i][j] == f[i+1][j+1] and f[i][j] != f[i+1][j] and f[i][j] == f[i][j+1]) ans++;
                        else if(f[i][j] == f[i+1][j+1] and f[i][j] == f[i+1][j] and f[i][j] != f[i][j+1]) ans++;
                }
        }
        return ans;
}

void input()
{
        cin >> h >> w;
        for (int i = 0; i < h; i++) cin >> f[i];
}

int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        cout << fixed << setprecision(12);
        input();
        cout << solve() << endl;
        return 0;
}
