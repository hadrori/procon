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
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

/* 内積 */
double dot(const P& a, const P& b) {
    return real(conj(a)*b);
}

/* 外積 */
double cross(const P& a, const P& b) {
    return imag(conj(a)*b);
}

/* 点と多角形の包含関係 */
#define curr(g, i) g[i]
#define next(g, i) g[(i+1)%g.size()]
enum { OUT, ON, IN };
int contains(const G& g, const P& p) {
    bool in = false;
    for (int i = 0; i < g.size(); ++i) {
        P a = curr(g,i) - p, b = next(g,i) - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b))
            if (cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}

int main(){
    G g(3);
    P p = P(0,0);
    int ans = 0;
    while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf", 
                 &g[0].real(), &g[0].imag(),
		 &g[1].real(), &g[1].imag(),
		 &g[2].real(), &g[2].imag())){
	if(contains(g,p)) ans++;
    }
    cout << ans << endl;
}
