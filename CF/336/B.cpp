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

#define rep(i,a) for(ll i = 0;i < (a); i++)
#define repi(i,a,b) for(ll i = (a); i < (b); i++)
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
#define EPS 1e-8
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int main(){
    ll m;
    double R;
    cin >> m >> R;
    double ans = 0;
    repi(i,1,m){
//	cerr << 2 * m - 2 * i << " , " << sqrt((2*i-1)*(2*i-1)+1) << endl;
	if(i == 1) ans += sqrt(2) * 2 * (m - 1);
	else ans += (2*(i-2)+2*sqrt(2)) * 2 * (m - i);
    }
    ans /= m * m;
    ans *= R;
    ans += 2 * R;
    printf("%.10f\n", ans);
    return 0;
}
