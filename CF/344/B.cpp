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
    int a, b, c;
    cin >> a >> b >> c;
    int x = a + b - c, y = -a + b + c, z = a - b + c;
    if(x % 2 || y % 2 || z % 2 ||
       x < 0 || y < 0 || z < 0 ||
       (x == 0 && y == 0) || (y == 0 && z == 0) || (z == 0 && x == 0))
	 cout << "Impossible" << endl;
    else cout << x / 2 << ' ' << y / 2 << ' ' << z / 2 << endl;
    return 0;
}
