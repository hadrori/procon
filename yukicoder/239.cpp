#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int fm[] = {3,5,17,257,65537};

int n;

int solve() {
    int ans = -2;
    for (int i = 1; i <= n; i<<=1) {
        for (int j = 0; j < 1<<5; j++) {
            i64 f = i;
            for (int k = 0; k < 5; k++) if(j>>k&1) f *= fm[k];
            if(f <= n) ans++;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    printf("%d\n", solve());
    return 0;
}
