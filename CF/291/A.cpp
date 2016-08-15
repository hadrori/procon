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
    vi id(n);
    rep(i,n) cin >> id[i];

    sort(all(id));
    int ans = 0, cnt = 0;
    int prev = -1;
    rep(i,n){
	if(!id[i]) continue;
	if(id[i] == prev){
	    if(++cnt >= 3){
		ans = -1;
		break;
	    }
	    if(cnt == 2) ans++;
	}
	else cnt = 1;
	prev = id[i];
    }
    cout << ans << endl;
    return 0;
}
