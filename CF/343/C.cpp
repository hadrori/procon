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
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int n, m;
vector<ll> h, p;

bool can(ll tim){
    int cur = 0;
    rep(i,n){
	if(cur == m) break;
	ll t = p[cur];
	if(t >= h[i]){
	    while(cur < m && p[cur] - h[i] <= tim) cur++;
	}
	else{
	    if(h[i] - t > tim) return false;
	    while(cur < m && p[cur] <= h[i]) cur++;
	    while(cur < m && p[cur] - t + min(h[i] - t, p[cur] - h[i]) <= tim) cur++;
	}
    }
    return cur == m;
}

int main(){
    cin >> n >> m;
    h.resize(n); p.resize(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> p[i];
    
    if(m == 0){
	cout << 0 << endl;
	return 0;
    }
    
    ll lb = -1, ub = 20000000000;
    while(lb + 1 < ub){
//	cerr << lb << ' ' << ub << endl;
	ll mid = (lb + ub) / 2;
	if(can(mid)) ub = mid;
	else lb = mid;
    }
    cout << ub << endl;
    return 0;
}
