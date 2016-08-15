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
    rep(i,2*n+1){
	if(i <= n){
	    rep(j,n-i) cout << "  ";
	    rep(j,2*i+1){
		if(j <= i) cout << j;
		else cout << 2*i-j;
		cout << (j==2*i? '\n': ' ');
	    }
	}
	else {
	    rep(j,i-n) cout << "  ";
	    rep(j,2*(2*n-i)+1){
		if(j <= 2*n-i) cout << j;
		else cout << 2*(2*n-i)-j;
		cout << (j==2*(2*n-i)? '\n': ' ');
	    }
	}
    }
    return 0;
}
