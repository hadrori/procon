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
    int r, c;
    cin >> r >> c;
    vector<string> cake(r);
    rep(i,r) cin >> cake[i];
    int ans = 0;
    rep(i,r){
	bool ok = true;
	rep(j,c) if(cake[i][j] == 'S'){
	    ok = false;
	    break;
	}
	if(ok)rep(j,c){
		if(cake[i][j] == '.') ans++;
		cake[i][j] = '#';
	}
    }
    rep(j,c){
	bool ok = true;
	rep(i,r) if(cake[i][j] == 'S'){
	    ok = false;
	    break;
	}
	if(ok)rep(i,r){
		if(cake[i][j] == '.') ans++;
		cake[i][j] = '#';
	}
    }
    cout << ans << endl;
    return 0;
}
