#include <bits/stdc++.h>
using namespace std;

int h, w;
string f[64];

int solve()
{
        int ans = 0;
        for (int i = 0; i < h-1; i++) {
                for (int j = 0; j < w-1; j++) {
                        char cs[4];
                        int k = 0;
                        for (int ii = i; ii < i+2; ii++) {
                                for (int jj = j; jj < j+2; jj++) {
                                        cs[k++] = f[ii][jj];
                                }
                        }
                        sort(cs,cs+4);
                        if(cs[0] == 'a' and cs[1] == 'c' and cs[2] == 'e' and cs[3] == 'f') ans++;
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
        input();
        cout << solve() << endl;
        return 0;
}
