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
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    int step = 1;
    rep(i,m){
	int t, l, r;
	cin >> t >> l >> r;
	if(s == f) continue;
	while(step < t){
	    if(f > s){
		s++;
		cout << "R";
	    }
	    else if(f < s){
		s--;
		cout << "L";
	    }
	    else break;
	    step++;
	}
	if(f > s && (s + 1 > r || s + 1 < l) && (s > r || s < l)){
	    s++;
	    cout << "R";
	}
	else if(f < s && (s - 1 > r || s - 1 < l) && (s > r || s < l)){
	    s--;
	    cout << "L";
	}
	else if(s != f)cout << "X";
	step++;
    }
    while(s != f){
	if(f > s){
	    s++;
	    cout << "R";
	}
	else if(f < s){
	    s--;
	    cout << "L";
	}
    }
    cout << endl; 
    return 0;
}
