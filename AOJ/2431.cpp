#include <bits/stdc++.h>
using namespace std;

struct segtree  // RMQ
{
        int N;
        vector<long long> dat;
        segtree(int n) {
                N = 1;
                while(N < n) N *= 2;
                dat.assign(2*N, 0);
        }
        // update k th element
        void update(int k, long long a) {
                k += N-1; // leaf
                dat[k] = a;
                while(k > 0){
                        k = (k - 1) / 2;
                        dat[k] = max(dat[k*2+1], dat[k*2+2]);
                }
        }
        // min [a, b)
        long long query(int a, int b){ return query(a, b, 0, 0, N);}
        long long query(int a, int b, int k, int l, int r) {
                if(r <= a or b <= l) return 0;
                if(a <= l and r <= b) return dat[k];
                int m = (l + r) / 2;
                return max(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
        }
};

long long n, x[100010];

long long solve()
{
        segtree st(n+1);
        for (int i = 0; i < n; i++) st.update(x[i], st.query(0,x[i])+x[i]);
        return 1LL*n*(n+1)/2-st.query(0,n+1);
}

void input()
{
        scanf("%lld", &n);
        for (int i = 0; i < n; i++) scanf("%lld", x+i);
}

int main()
{
        input();
        printf("%lld\n", solve());
        return 0;
}
