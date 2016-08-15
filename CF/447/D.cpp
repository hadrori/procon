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
typedef long long ll;

const int MAX = 1024;
// BIT is 0 indexed
struct BIT{
    int bit[MAX], N;
    BIT(){}
    BIT(int N):N(N){
        memset(bit, 0, sizeof(bit));
    }
    // sum [0,i]
    int sum(int i){
        i++;
        int ret = 0;
        while(i){
            ret += bit[i];
            i -= i&-i;
        }
        return ret;
    }
    // sum [i,j)
    int sum(int i, int j){
        return sum(j-1) - sum(i-1);
    }
    
    void add(int i, int x){
        i++;
        while(i <= N){
            bit[i] += x;
            i += i&-i;
        }
    }
};


int n, m, k, p;
int a[1024][1024];
BIT r[1024], c[1024];

ll solve(){
    ll ans = 0;
    return ans;
}

void input(){
    scanf("%d%d%d%d", &n, &m, &k, &p);
    rep(i,n)rep(j,m){
        scanf("%d", &a[i][j]);
        r[i].add(j,a[i][j]);
        c[j].add();
    }
}

signed main(){
    input();
    cout << solve() << endl;
    return 0;
}
