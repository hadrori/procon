#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

const int mod = 1000000009;

int n, m, k;
/* 冪剰余 */
// x^k % m
long long pow_mod(long long x, long long k, long long m) {
    if (k == 0)     return 1;
    if (k % 2 == 0) return pow_mod(x*x % m, k/2, m);
    else            return x*pow_mod(x, k-1, m) % m;
}

int main(){
    cin >> n >> m >> k;
    int sep = n - m;
    int need = n / k;
    if(sep >= need) cout << m << endl;
    else {
	int sh = need - sep;
	cout << (m + (pow_mod(2, sh + 1, mod)  - sh - 2 + mod) % mod * k % mod) % mod << endl;
    }
    return 0;
}
