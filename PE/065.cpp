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
    ll a, num;
    S(ll a, ll num):a(a),num(num){}
};

const int N = 100;

int main(){
    vector<S> seq;
    seq.pb(S(2, 1));
    while(seq.size() < N){
	int n = seq.size();
	if(n % 3 == 2) seq.pb(S(2*(n/3+1), 1));
	else seq.pb(S(1, 1));
	cerr << seq[n].a << ' ' << seq[n].num << endl;
    }
    seq[N-1].num = 0;
    repd(i,N-2,1){
	seq[i-1].num = seq[i+1].a + seq[i+1].num;
	seq[i].a *= seq[i+1].a;
    }
    rep(i,N) cerr << seq[i].a << ' ' << seq[i].num << endl;
    cout << seq[0].a * seq[1].a + seq[0].num << " / " << seq[1].a << endl;
    return 0;
}
