#include "bits/stdc++.h"
using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
using uint = unsigned;
using number = uint;
using arr = vector<number>;
using mat = vector<arr>;

mat ident(int n) {
    mat A(n,arr(n,0));
    rep(i,n) A[i][i] = -1;
    return A;
}

arr mul(const mat &A, const arr &x) {
    arr y(A.size());
    for(int i = 0; i < (int)A.size(); ++i)
        for(int j = 0; j < (int)A[0].size(); ++j)
            y[i] ^= A[i][j] & x[j];
    return y;
}

mat mul(const mat &A, const mat &B) {
    mat C(A.size(), arr(B[0].size()));
    for(int i = 0; i < (int)C.size(); ++i)
        for(int j = 0; j < (int)C[i].size(); ++j)
            for(int k = 0; k < (int)A[i].size(); ++k)
                C[i][j] ^= A[i][k] & B[k][j];
    return C;
}

mat pow(mat A, int e) {
    mat B = ident(A.size());
    for(;e>0;A=mul(A,A),e>>=1) if(e&1) B = mul(B,A);
    return B;
}

int k, m;
vector<uint> a, c;

uint solve() {
    mat A(k+1,arr(k+1,0));
    repi(i,1,k+1) A[i][i-1] = -1;
    rep(i,k) A[0][i] = c[i];
    reverse(begin(a),end(a));
    a = mul(pow(A,m),a);
    return a.back();
}

void input() {
    cin >> k >> m;
    a.resize(k); c.resize(k);
    rep(i,k) cin >> a[i];
    rep(i,k) cin >> c[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
