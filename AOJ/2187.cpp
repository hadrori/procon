#include <bits/stdc++.h>
using namespace std;

int a[2][16];

void solve()
{
        int sum = 0, win = 0;
        sort(a[0], a[0]+9);
        do {
                int pt = 0;
                for (int i = 0; i < 9; i++)
                        if(a[0][i] > a[1][i]) pt += a[0][i]+a[1][i];
                if(pt > 85) win++;
                sum++;
        } while(next_permutation(a[0], a[0]+9));
        const double x = 1.*win/sum, y = 1.-x;
        printf("%.5f %.5f\n", x, y);
}

int main()
{
        int t; scanf("%d", &t);
        while(t--) {
                for (int i = 0; i < 2; i++)
                        for (int j = 0; j < 9; j++)
                                scanf("%d", a[i]+j);
                solve();
        }
        return 0;
}
