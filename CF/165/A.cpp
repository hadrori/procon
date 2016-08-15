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

struct S{
    int x, y;
    bool d[4];
    S(int x, int y):x(x),y(y){
	memset(d,0,sizeof(d));
    }
};

int main(){
    int n;
    cin >> n;
    vector<S> table;
    rep(i,n){
	int x, y;
	cin >> x >> y;
	table.pb(S(x, y));
	rep(j,i){
	    if(x > table[j].x && y == table[j].y){
		table[j].d[0] = true;
		table[i].d[1] = true;
	    }
	    else if(x < table[j].x && y == table[j].y){
		table[j].d[1] = true;
		table[i].d[0] = true;
	    }
	    else if(x == table[j].x && y > table[j].y){
		table[j].d[2] = true;
		table[i].d[3] = true;
	    }
	    else if(x == table[j].x && y < table[j].y){
		table[j].d[3] = true;
		table[i].d[2] = true;
	    }
	}
    }
    int ans = 0;
    rep(i,n)
	if(table[i].d[0] && table[i].d[1] &&
	   table[i].d[2] && table[i].d[3])
	    ans++;
    cout << ans << endl;
    return 0;
}
