#include <bits/stdc++.h>
using namespace std;

const double H = 50, W = 100, D = 30;

double q[16];
int n, b[16], h[16], f[16], l;

inline double height(int i) { return q[i]/(b[i+1]-b[i])/D; }

void solve()
{
        int pt = 0;
        memset(q,0,sizeof(q));
        while(l--) {
                int p, t;
                scanf("%d%d", &p, &t);
                for (int i = 0; i <= n; i++) q[i] = 1.*t*f[i];
                bool updated;
                do {
                        updated = 0;
                        for (int i = 0; i < n; i++) {
                                double mh = height(i);
                                if(!i) 
                        }
                } while(updated);
                printf("%.12f\n", height(lower_bound(b,b+n,p)-b));
        }
}

void init()
{
        memset(f,0,sizeof(f));
        h[0] = h[n+1] = H;
        b[0] = 0;
        b[n+1] = W;
}

void input()
{
        scanf("%d", &n);
        init();
        for (int i = 0; i < n; i++) scanf("%d%d", b+1+i, h+1+i);
        n++;
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
                int x, y;
                scanf("%d%d", &x, &y);
                f[lower_bound(b,b+n,x)-b] += y;
        }
        scanf("%d", &l);
}

int main()
{

        int t; scanf("%d", &t);
        while(t--) {
                input();
                solve();
        }
        return 0;
}
