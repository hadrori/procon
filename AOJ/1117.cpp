#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const double eps = 1e-8;

typedef vector<double> arr;
typedef vector<arr> mat;

arr gauss_jordan(const mat& A, const arr& b) {
    int W = A[0].size();
    int H = A.size();

    mat B(H, arr(W + 1));

    for(int y = 0; y < H; y++)
        for(int x = 0; x < W; x++) B[y][x] = A[y][x];

    for(int y = 0; y < H; y++) B[y][W] = b[y];

    bool unique = true;
    int cy = 0;

    for(int x = 0; x < W; x++){
        int pivot = cy;
        for(int y = cy; y < H; y++) if(abs(B[y][x]) > abs(B[pivot][x])) pivot = y;
        if(pivot >= H || abs(B[pivot][x]) < eps) {
            unique = false;
            continue;
        }
        swap(B[cy], B[pivot]);
        for(int x2 = x + 1; x2 <= W; x2++) B[cy][x2] /= B[cy][x];
        for(int y = 0; y < H; y++) if(y != cy) for(int x2 = x + 1; x2 <= W; x2++) B[y][x2] -= B[y][x] * B[cy][x2];
        cy++;
    }

    if(!unique) return arr();
    for(int y = cy; y < H; y++) if(abs(B[y][W]) > eps) return arr();

    arr v(W);
    int cur_x = 0;
    for(int y = 0; y < H; y++)
        if(abs(B[y][cur_x]) > eps)
            v[cur_x++] = B[y][W];
    return v;
}

int h, w, id[128][16];
string f[128][16];

void solve() {
    memset(id,-1,sizeof(id));
    int m = 0;
    rep(i,h) rep(j,w) if(f[i][j] == "?") id[i][j] = m++;
    arr b(h+w-2);
    mat a(h+w-2,arr(m,0));
    rep(i,h-1) {
        b[i] = atoi(f[i][w-1].c_str());
        rep(j,w-1) {
            if(~id[i][j]) a[i][id[i][j]] = 1;
            else b[i] -= atoi(f[i][j].c_str());
        }
    }
    rep(j,w-1) {
        b[j+h-1]= atoi(f[h-1][j].c_str());
        rep(i,h-1) {
            if(~id[i][j]) a[j+h-1][id[i][j]] = 1;
            else b[j+h-1] -= atoi(f[i][j].c_str());
        }
    }

    arr x = gauss_jordan(a,b);
    if(!x.size()) puts("NO");
    else rep(i,m) cout << int(round(x[i])) << endl;
}

bool input() {
    cin >> h;
    if(!h) return 0;
    cin >> w;
    h++; w++;
    rep(i,h) rep(j,w) cin >> f[i][j];
    return 1;
}

int main() {
    for(int t = 0; input(); t++) {
        if(t) puts("");
        solve();
    }
    return 0;
}
