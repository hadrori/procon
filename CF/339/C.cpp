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

string w;
int memo[1024], m;

bool rec(int n, int k){
    if(n == m + 1) return true;
    bool ok = false;
    repi(i,1,11){
	int tw = w[i-1] - '0';
	memo[n] = memo[(n + 1022) % 1024] + i;
	if(tw && i != k && memo[n-1] < memo[n]){
//	    cerr << n << ' ' << tw << ' ' << i << endl;
	    ok = rec(n+1,i);
	    if(ok) break;
	}
    }
    return ok;
}
int main(){
    cin >> w >> m;
    if(!rec(1,0)) cout << "NO\n";
    else{
	cout << "YES\n";
	rep(i,m) cout << memo[i+1] - memo[(i + 1023) % 1024] << ' ';
	cout << endl;
    }
    return 0;
}
