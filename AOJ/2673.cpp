#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
int n;
double x[128], y[128], sum[2];

void integrate(int u, int v)
{
        if(abs(x[u]-x[v]) < eps) return;

        const double dx = x[v] < x[u]? -0.5: 0.5, dy = (y[v]-y[u])/(x[v]-x[u])*dx;
        int f = x[v]<x[u]? 1: 0;
        double cx = x[u], cy = y[u];
        while(abs(cx-x[v]) > eps) {
                const double nx = cx+dx, ny = cy+dy;
                sum[f] -= dx*(ny+cy)/2;
                f ^= 1;
                cx = nx;
                cy = ny;
        }
}

double solve()
{
        for (int i = 0; i < n; i++) integrate(i,(i+1)%n);
        return max(sum[0], sum[1]);
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lf%lf", x+i, y+i);
}

int main()
{
        input();
        printf("%.8f\n", solve());
        return 0;
}
