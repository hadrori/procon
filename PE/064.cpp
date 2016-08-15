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
#define EPS 1e-7
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;
typedef complex<int> Q;

const int N = 10000;

struct S{
    int a, num;
    Q den;
    S(int a, int num, Q den):a(a),num(num),den(den){}
    bool operator == (const S &s)const{
	return num == s.num && den == s.den;
    }
};

bool isSq(int n){
    for(int i = 2; i * i <= n; i++)if(i * i == n) return true;
    return false;
}

int main(){
    int ans = 0;
    repi(i,2,N+1){
	if(isSq(i)) continue;
	int s = (int)sqrt(i);
	vector<S> seq;
	seq.pb(S(s,1,Q(i,-s)));
//	cerr << s << " , " << 1 << " / " << Q(i,-s) << endl;
	while(1){
	    int n = seq.size() - 1;
	    int pa = seq[n].a;
	    int pnum = seq[n].num;
	    Q pden = seq[n].den;
	    int a = (int)(pnum / (sqrt(pden.real()) + pden.imag()));
	    int num = pden.real() - pden.imag()*pden.imag();
	    int g = __gcd(pnum,num);
	    pnum /= g; num /= g;
	    Q den;
	    den.real() = pden.real();
	    den.imag() = -pden.imag() - num * a;
	    seq.pb(S(a,num,den));
//	    cerr << a << " , " << num << " / " << den << endl;
	    if(seq[0] == seq[n+1]){
//		cerr << "period = " << n - t + 1 << endl;
		if((n - 1) % 2){
		    ans++;
//		    cerr << ans << endl;
		}
//		cerr << "------------------------------------\n";
		break;
	    }
	}
    }
    cout << ans << endl;
    return 0;
}
