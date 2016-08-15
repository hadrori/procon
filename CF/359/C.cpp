#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

const ll mod = 1000000000 + 7;

/* 冪剰余 */
// x^k % m
long long pow_mod(long long x, long long k, long long m) {
    if (k == 0)     return 1;
    if (k % 2 == 0) return pow_mod(x*x % m, k/2, m);
    else            return x*pow_mod(x, k-1, m) % m;
}

ll n, x, sum;
vector<int> a;

int main(){
    cin >> n >> x;
    a.resize(n);
    
    rep(i,n){
        int tmp;
        cin >> tmp;
        if(tmp){
            a.pb(tmp);
            sum += tmp;
        }
    }
    n = a.size();
    if(a[n-1] == 0) cout << 1 << endl;
    else if(n <= 1) cout << 1 << endl;
    else{
        if(a[n-1] != a[n-2]) cout << pow_mod(x, sum - a[n-1], mod) << endl;
        else{
            ll ans = pow_mod(x, sum - a[n-1], mod);
            ll cnt = 1;
            ll cur = n-2;
            while(cur >= 0 && a[cur] == a[n-1]) {
                cnt++;
                cur--;
            }
            cnt /= x;
            if(cnt) ans *= (cnt * x) % mod;
            ans %= mod;
            cout << ans << endl;
        }
    }
    

    return 0;
}
