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

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    repd(i,29,0){
	int cur = -1;
	int k = 0;
	rep(j,n)if(a[j] & (1 << i)){
	    cur &= a[j];
	    k++;
	}
	if(cur % (1 << i) == 0){
	    cout << k << endl;
	    rep(l,n)if(a[l] & (1 << i)){
		k--;
		cout << a[l] << (k? " ": "\n");
	    }
	    return 0;
	}
    }
    cout << -1 << endl;
    return 0;
}
