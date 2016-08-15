#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
typedef long long i64;
const i64 M = 10000000;
int k, a[1<<20], b[M+10];
bool p[M+10];

i64 solve() {
    rep(i,k) b[a[i]]++;
    for (int i = M; i > 1; i--) b[i] += b[i+1];

    i64 ans = 0;
    p[0] = p[1] = 1;
    rep(i,M+1) if(!p[i]) {
        i64 cnt = 0;
        for (int j = i+i; j <= M; j+=i) p[j] = 1;
        for (i64 j = i; j <= M; j*=i)
            for (i64 k = j; k <= M; k+=j) cnt += b[k];
                

        i64 lb = 0, ub = M*M, mid, sum;
        while(ub-lb > 1) {
            sum = 0;
            mid = (lb+ub)/2;
            for (i64 j = i; j <= mid; j*=i) sum += mid/j;
            if(sum >= cnt) ub = mid;
            else lb = mid;
        }
        ans = max(ans, ub);
    }
    return ans;
}

void input() {
    cin >> k;
    rep(i,k) cin >> a[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    cout << solve() << endl;
    return 0;
}
