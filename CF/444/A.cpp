#include <bits/stdc++.h>
using namespace std;
#define double long double

int n, m;
int G[512][512], x[512];

double solve()
{
        double ans = 0;
        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                        if(G[i][j]) ans = max(ans, 1.L*(x[i]+x[j])/G[i][j]);
                }
        }
        return ans;
}

void input()
{
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
                cin >> x[i];
        }
        for (int j = 0; j < m; j++) {
                int a, b, c;
                cin >> a >> b >> c;
                a--; b--;
                G[a][b] = G[b][a] = c;
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        cout << fixed << setprecision(12);
        input();
        cout << solve() << endl;
        return 0;
}
