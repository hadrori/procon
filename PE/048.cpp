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
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MAX = 1000;
const ull mod = 10000000000;

/* 冪剰余 */
// x^k % mod
ull pow_mod(ull x, ull k) {
    if (k == 0)     return 1;
    if (k % 2 == 0) return pow_mod(x*x % mod, k/2);
    else            return x*pow_mod(x, k-1) % mod;
}

int main(){
    ull sum = 0;
    repi(i,1,MAX+1){
        sum += pow_mod(i,i);
        sum %= mod;
    }
    cout << sum << endl;
}
