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

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

bool inrange(int x, int y){
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

int main(){
    int table[3][3], ans[3][3];
    rep(i,3)rep(j,3) ans[i][j] = 1;
    rep(x,3)rep(y,3){
	int t;
	cin >> t;
	t %= 2;
	if(t){
	    ans[x][y] ^= 1;
	    rep(k,4) if(inrange(x+dx[k], y+dy[k]))
		ans[x+dx[k]][y+dy[k]] ^= 1;
	}
    }
    rep(i,3)rep(j,3) cout << ans[i][j] << (j==2? "\n": "");
    return 0;
}
