#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;

int n, a[100010];

int solve(){
    int l = 0, r = 1, rv = 0, pr = a[0], ans = 1, tmp = 0;
    while(r < n){
        if(pr >= a[r]){
            if(rv){
                l = tmp;
                pr = a[r-1];
                rv = 0;
            }
            else {
                tmp = r;
                r++; pr++;
                rv = 1;
            }
        }
        else pr = a[r++];
        ans = max(ans, r-l);
    }
    reverse(a,a+n);
    l = 0, r = 1, rv = 0, pr = a[0], tmp = 0;
    while(r < n){
        if(pr <= a[r]){
            if(rv){
                l = tmp;
                pr = a[r-1];
                rv = 0;
            }
            else {
                tmp = r;
                r++; pr--;
                rv = 1;
            }
        }
        else pr = a[r++];
        ans = max(ans, r-l);
    }
    return ans;
}

void input(){
    scanf("%d", &n);
    rep(i,n) scanf("%d", a+i);
}

int main(){
    input();
    printf("%d\n", solve());
    return 0;
}
