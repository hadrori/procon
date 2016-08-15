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
    int n, e;
    ll sum = 0;
    cin >> n;
    //    n--;
    rep(i,32){
        sum += 5*(1<<i);
        //	cerr << sum << endl;
        if(n <= sum){
            n -= sum - max(0, 5*(1<<i));
            n--;
            //	    cerr << n << ' ' << (1<<i) << endl;
            n /= (1LL<<i);

            cout << (n==0? "Sheldon": n==1? "Leonard": n==2? "Penny":
                     n==3? "Rajesh": "Howard") << endl;
            break;
        }
    }
    return 0;
}
