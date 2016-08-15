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
    int n, m;
    cin >> n >> m;
    vi a(1<<n);
    rep(i,1<<n)
	cin >> a[i];
    bool exflag = false;
    vi t = a;
    while(t.size() > 1){
	rep(j,t.size()-1){
	    if(exflag)t[j] ^= t[j+1];
	    else t[j]|= t[j+1];
	    t.erase(t.begin()+j+1);
	}
	exflag ^= true;
    }

    int v = t[0];
    rep(i,m){
	int p, b;
	cin >> p >> b;
	if(a[p] | b == a[p]) cout << v << endl;
	else{
	    if(p%2 == 0 && a[p+1] | b == a[p+1]){
		int k = -1 ^ b | a[p];
		cout << v ^ k << endl;
	    }else if (p%2 && a[p-1] | b == a[p-1]){
		int k = -1 ^ b | a[p];
		cout << v ^ k << endl;
	    }else {

	    }
	}

	cout << t[0] << endl;
    }
    
    return 0;
}
