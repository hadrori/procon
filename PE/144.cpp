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

int sig(double r) { return r < -EPS ? -1 : r > EPS ? 1 : 0; }

/* 点 */
struct P {
    double x, y;

    P() {}
    P(double x, double y) : x(x), y(y) {}

    /* 演算子 */
    P operator+(const P &a) const { return P(x + a.x, y + a.y); }
    P operator-(const P &a) const { return P(x - a.x, y - a.y); }
    P operator-() const { return P(-x, -y); }
    P operator*(const P &a) const { return P(x * a.x - y * a.y, x * a.y + y * a.x); }
    P operator*(const double &k) const { return P(x * k, y * k); }
    P operator/(const double &k) const { return P(x / k, y / k); }
    bool operator<(const P &a) const { return x != a.x ? x < a.x : y < a.y; }
    bool operator==(const P &a) const { return sig(x - a.x) == 0 && sig(y - a.y) == 0; }

    double norm() const { return x * x + y * y; }
    double abs() const { return sqrt(norm()); }     //距離
    double arg() const { return atan2(y, x); }      //傾き
    double dot(const P &a) const { return x * a.x + y * a.y; } //内積
    double det(const P &a) const { return x * a.y - y * a.x; } //外積
    P proj(const P &a) const { double k = dot(a) / norm(); return P(x * k, y * k); } //正射影
};

/* 出力 */
ostream &operator<<(ostream&os, const P&a) { os << "(" << a.x << ", " << a.y << ")"; return os; }

struct L {
    P a, b;

    L() {}
    L(P a, P b) : a(a), b(b) {}

    P vec() const { return b - a; } //ベクトル
    P proj(const P &p) const { return a + vec().proj(p - a); }  //正射影
    P refl(const P &p) const { return proj(p) * 2 - p; }        //線対称な点
};

int main(){
    P cur = P(1.4,-9.6);
    P prev = P(0,10.1);
    
    int ans = 0;
    while(true){
	if(abs(cur.x) <= 0.01 && cur.y > 0) break;
	L n = L(cur, cur + P(4 * cur.x, cur.y)); //鏡の法線
	P next = n.refl(prev);
	P beam = L(cur,next).vec();
	double s = beam.y / beam.x;
	double t = cur.y - cur.x * s;
	double D = 25 * s * s - t * t + 100;
	double A = s * s + 4;
	P p = P(-s*t-2*sqrt(D), 4*t-2*s*sqrt(D)) / A;
	P q = P(-s*t+2*sqrt(D), 4*t+2*s*sqrt(D)) / A;
	prev = cur;
	if((prev - p).abs() < EPS) cur = q;
	else cur = p;
	ans++;
//	cerr << cur << endl;
    }
    cout << ans << endl;
    return 0;
}
