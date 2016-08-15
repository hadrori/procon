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
    int p[3];
    rep(i,3) cin >> p[i];
    sort(p,p+3);
    repi(i,1,p[2]+1)repi(j,i,p[2]+1){
	bool used[3] = {false}, flag = false;
	int q = i * j;
	rep(a,3)if(p[a] == q){
	    used[a] = true;
	    flag = true;
	    break;
	}
	if(!flag) continue;
	int p1, p2;
	rep(a,3)if(!used[a]){
	    p1 = p[a];
	    used[a] = true;
	    break;
	}
	rep(a,3)if(!used[a]){
	    p2 = p[a];
	    used[a] = true;
	    break;
	}
	if(p1 % i) swap(p1,p2);
	if(p1 % i) continue;
	if(p2 % j) continue;
	int k = p1 / i;
	if(k != p2 / j) continue;
	cout << (i + j + k) * 4 << endl;
	return 0;
    }
    return 0;
}
