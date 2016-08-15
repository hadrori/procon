#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define my_unique(u) (u).erase(unique(all(u)),end(u))
#define dump(x) cerr << #x << " = " << x << endl;
#define hoge cerr << "hogehoge" << endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fst first
#define snd second
const double pi = acos(-1.0);
const int inf = 1e9;
const double eps = 1e-9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
template<class T> inline T sq(T x) { return x * x;}
template<class T> inline T mypow(T x, int e) { return e == 0? 1: e%2? x * pow(x,e-1): pow(x*x,e/2);}
template<class T> inline void chmax(T &x, T y) { if(x < y - eps) x = y;}
template<class T> inline void chmin(T &x, T y) { if(x > y + eps) x = y;}
inline bool eq(double x, double y) { return abs(x - y) < eps;}
inline int pow2(int e) { return 1LL << e;}
inline int lcm(int x, int y) { return x * y / __gcd(x,y);}
inline int to_int(string s) { return atoi(s.c_str());}
int w, h;
inline bool inrange(int x, int y) { return x > 0 && x < w && y > 0 && y < h;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef complex<double> point;
typedef vector<point> graph;
typedef int Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

bool input(){
    return 0;
}

int solve(){
    return 0;
}

signed main(){
    while(input()){ cout << solve() << endl;}
    return 0;
}
