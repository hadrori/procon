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
    sort(all(a));
    vector<vi> ans(n/3);
    int m = n / 3;
    rep(i,m)
	if(a[i] == 1)ans[i].pb(1);
	else {
	    cout << -1 << endl;
	    return 0;
	}
    rep(i,m)
	if(a[i+m] == 2 || a[i+m] == 3) ans[i].pb(a[i+m]);
	else {
	    cout << -1 << endl;
	    return 0;
	}
    rep(i,m)
	if(ans[i][1] == 2 && (a[i+2*m] == 4 || a[i+2*m] == 6)) ans[i].pb(a[i+2*m]);
	else if(ans[i][1] == 3 && a[i+2*m] == 6) ans[i].pb(6);
	else {
	    cout << -1 << endl;
	    return 0;
	}
    rep(i,m)rep(j,3) cout << ans[i][j] << (j==2? '\n': ' ');
    return 0;
}
