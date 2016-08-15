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

int gcd(int a, int b){
    return (b>0)? gcd(b, a%b) : a ;
}
int lcm(int a, int b){
    return (a / gcd(a, b) * b);
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int p1 = a*d - b*c, p2 = b*c - a*d;
    int q1 = a*d, q2 = b*c;
//    cerr << p1 << ' ' << p2 << endl;
    if(p1 < 0){
	int t = gcd(p2, q2);
	p2 /= t; q2 /= t;
	cout << p2 << '/' << q2 << endl;
    }else if(p2 <= 0){
	int t = gcd(p1, q1);
	p1 /= t; q1 /= t;
	cout << p1 << '/' << q1 << endl;
    }
    /*
      else if(1.0*p1/q1 < 1.0*p2/q2){
	int t = gcd(p1, q1);
	p1 /= t; q1 /= t;
	cout << p1 << '/' << q1 << endl;
    }else{
	int t = gcd(p2, q2);
	p2 /= t; q2 /= t;
	cout << p2 << '/' << q2 << endl;
    }
    */
    return 0;
}
