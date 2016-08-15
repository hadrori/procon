#include "bits/stdc++.h"
namespace D2 {
const double eps = 1e-8;
bool eq(const double &a, const double &b) { return std::abs(a-b)<eps; }

struct point {
    double x, y;
    point():x(0),y(0) {}
    point(double x, double y):x(x),y(y) {}

    point operator+=(const point &p) { x+=p.x; y+=p.y; return *this; }
    point operator-=(const point &p) { x-=p.x; y-=p.y; return *this; }
    point operator*=(const point &p) { double tx = x; x=x*p.x-y*p.y; y=y*p.x+tx*p.y; return *this; }
    point operator*=(const double &d) { x*=d; y*=d; return *this; }
    point operator/=(const double &d) { x/=d; y/=d; return *this; }
    point operator+(const point &p) const { return point(*this)+=p; }
    point operator-(const point &p) const { return point(*this)-=p; }
    point operator*(const double &d) const { return point(*this)*=d; }
    point operator*(const point &p) const { return point(*this)*=p; }
    point operator/(const double &d) const { return point(*this)/=d; }
    point operator-() const { return point(-x,-y); }
    bool operator<(const point &p) const { return std::abs(x- p.x)>eps ? x < p.x-eps : y < p.y-eps; }
    bool operator==(const point &p) const { return std::abs(x-p.x)<eps and std::abs(y-p.y)<eps; }
    bool operator!=(const point &p) const { return !(point(*this)==p); }

    double norm() const { return x*x+y*y; }
    double abs() const { return sqrt(norm()); }
    double arg() const { return atan2(y, x); }
    double dot(const point &p) const { return x*p.x+y*p.y; }
    double cross(const point &p) const { return x*p.y-y*p.x; }
    double det(const point &p) const { return x*p.y-y*p.x; }
    point proj(const point &p) const { double k = dot(p)/norm(); return point(x*k,y*k); }
};
point operator*(const double &d, const point &p) { point q = p*d; return q; }
std::ostream &operator<<(std::ostream &os, const point &p) { os << "(" << p.x << "," << p.y << ")"; return os; }

point polar(const double &r, const double &th) { return point(r*std::cos(th),r*std::sin(th)); }
double abs(const point &p) { return p.abs(); }
double norm(const point &p) { return p.norm(); }
double dot(const point &a, const point &b) { return a.dot(b); }
double cross(const point &a, const point &b) { return a.cross(b); }
double det(const point &a, const point &b) { return a.det(b); }
double arg(const point &a) { return a.arg(); }
/*
 *           1
 *  ------------------
 *    -2 |a  0  b| 2
 *  ------------------
 *          -1
 */
int ccw(point a, point b, point c)
{
    b -= a, c -= a;
    if (b.cross(c) > eps)        return +1;
    if (b.cross(c) < -eps)       return -1;
    if (b.dot(c) < -eps)         return -2; // c -- a -- b
    if (b.norm() < c.norm()-eps) return +2; // a -- b -- c
    return 0;
}

struct line {
    point a, b;
    line(){}
    line(point a, point b) : a(a), b(b) {}

    point vec() const { return b-a; }
    double abs() const { return vec().abs(); }
    double norm() const { return vec().norm(); }
    point proj(const point &p) const { return a+vec().proj(p-a); }
    point refl(const point &p) const { return proj(p)*2-p; }
};
std::ostream &operator<<(std::ostream &os, const line &l) { os << l.a << " - " << l.b; return os; }

bool ill(const line &l, const line &m) { return std::abs(l.vec().det(m.vec())) > eps; }
bool ils(const line &l, const line &s) { return ccw(l.a,l.b,s.a)*ccw(l.a,l.b,s.b)<=0; }
bool isl(const line &s, const line &l) { return ils(l,s); }
bool iss(const line &s, const line &t) { return ils(s,t) and ils(t,s); }
point cll(const line &l, const line &m) { return l.a+l.vec()*(m.vec().det(m.a-l.a)/m.vec().det(l.vec())); }
double dlp(const line &l, const point &p) { return (l.proj(p)-p).abs(); }
double dpl(const point &p, const line &l) { return dlp(l,p); }
double dll(const line &l, const line &m) { return ill(l,m) ? 0.0 : dlp(l,m.a); }
double dps(const point &p, const line &s) { return ccw(s.a,s.b,s.proj(p)) ? std::min((s.a-p).abs(), (s.b-p).abs()) : (s.proj(p)-p).abs(); }
double dsp(const line &s, const point &p) { return dps(p,s); }
double dss(const line &s, const line &m) { return iss(s,m)? 0.0 : std::min(std::min(dps(m.a,s),dps(m.b,s)), std::min(dps(s.a,m),dps(s.b,m))); }

}

using namespace std;

#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

int n;
D2::line s;
vector<D2::point> ps;

int solve() {
    int sum = 0;
    rep(i,n) if(D2::iss(s,D2::line(ps[i],ps[(i+1)%n]))) sum++;
    return 1+sum/2;
}

D2::point inp() {
    D2::point p;
    cin >> p.x >> p.y;
    return p;
}

void input() {
    s = D2::line(inp(), inp());
    cin >> n;
    rep(i,n) ps.push_back(inp());
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
