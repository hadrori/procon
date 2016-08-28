#include "bits/stdc++.h"

#include "summation.cu"

using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int N = 1000000, M = 100;

int a[N], n;

void generate() { n = rand()%N; rep(i,n) a[i] = rand()%M; }

void solve() {
    srand(time(0));
    rep(_,100) {
        generate();
        int sum = accumulate(a,a+N,0);
        int gsum = summation::calc(a,n);
        puts("----------------------------");
        printf("length  : %d\n", n);
        printf("cpu sum : %d\n", sum);
        printf("gpu sum : %d\n", gsum);
        
    }
}

int main() {
    input();
    solve();
    return 0;
}
