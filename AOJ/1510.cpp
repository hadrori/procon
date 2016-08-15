#include <bits/stdc++.h>
using namespace std;

int n, m[2], a[2][32], f[8][8][8], h[8][8][8];
inline bool in(int x, int y, int z) { return 0 <= x and x < 5 and 0 <= y and y < 5 and 0 <= z and z < 5;}

void solve()
{
        while(n--) {
                memset(h,0,sizeof(h));
                for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                                for (int k = 0; k < 5; k++) {
                                        for (int x = -1; x < 2; x++) {
                                                for (int y = -1; y < 2; y++) {
                                                        for (int z = -1; z < 2; z++) {
                                                                if(!x and !y and !z) continue;
                                                                if(!in(i+x,j+y,k+z)) continue;
                                                                h[i+x][j+y][k+z] += f[i][j][k];
                                                        }
                                                }
                                        }
                                }
                        }
                }
                for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                                for (int k = 0; k < 5; k++) {
                                        int ex = 0;
                                        for (int l = 0; l < m[f[i][j][k]]; l++) {
                                                if(a[f[i][j][k]][l] == h[i][j][k]) {
                                                        ex = 1;
                                                        break;
                                                }
                                        }
                                        f[i][j][k] = ex;
                                }
                        }
                }

        }
        for (int i = 0; i < 5; i++) {
                if(i) cout << endl;
                for (int j = 0; j < 5; j++) {
                        for (int k = 0; k < 5; k++) {
                                cout << f[i][j][k];
                        }
                        cout << endl;
                }
        }

}

bool input()
{
        cin >> n;
        if(!n) return 0;
        for (int i = 0; i < 5; i++)
                for (int j = 0; j < 5; j++) {
                        string s; cin >> s;
                        for (int k = 0; k < 5; k++)
                                f[i][j][k] = s[k]-'0';
                }
        for (int i = 0; i < 2; i++) {
                cin >> m[i];
                for (int j = 0; j < m[i]; j++) cin >> a[i][j];
        }
        return 1;
}

int main()
{
        int t = 0;
        while(input()) {
                if(t) cout << endl;
                cout << "Case " << ++t << ":" << endl;
                solve();
        }
        return 0;
}
