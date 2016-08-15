#include <bits/stdc++.h>

namespace D2
{
const double eps = 1e-8;
bool eq(const double &a, const double &b) { return std::abs(a-b)<eps;}

struct point
{
        double x, y;
        point():x(0),y(0){}
        point(double x, double y):x(x),y(y){}

        point operator+=(const point &p){ x+=p.x; y+=p.y; return *this;}
        point operator-=(const point &p){ x-=p.x; y-=p.y; return *this;}
        point operator*=(const point &p){ double tx = x; x=x*p.x-y*p.y; y=y*p.x+tx*p.y; return *this;}
        point operator*=(const double &d){ x*=d; y*=d; return *this;}
        point operator/=(const double &d){ x/=d; y/=d; return *this;}
        point operator+(const point &p)const{ return point(*this)+=p;}
        point operator-(const point &p)const{ return point(*this)-=p;}
        point operator*(const double &d)const{ return point(*this)*=d;}
        point operator*(const point &p)const{ return point(*this)*=p;}
        point operator/(const double &d)const{ return point(*this)/=d;}
        point operator-()const{ return point(-x,-y);}
        bool operator<(const point &p) const { return std::abs(x- p.x)>eps ? x < p.x-eps : y < p.y-eps;}
        bool operator==(const point &p) const { return std::abs(x-p.x)<eps and std::abs(y-p.y)<eps;}
        bool operator!=(const point &p) const { return !(point(*this)==p);}

        double norm() const { return x*x+y*y;}
        double abs() const { return sqrt(norm());}
        double arg() const { return atan2(y, x);}
        double dot(const point &p) const { return x*p.x+y*p.y;}
        double cross(const point &p) const { return x*p.y-y*p.x;}
        double det(const point &p) const { return x*p.y-y*p.x;}
        point proj(const point &p) const { double k = dot(p)/norm(); return point(x*k,y*k);}
};
point operator*(const double &d, const point &p){ point q = p*d; return q;}
std::ostream &operator<<(std::ostream &os, const point &p) { os << "(" << p.x << "," << p.y << ")"; return os; }

point polar(const double &r, const double &th) { return point(r*std::cos(th),r*std::sin(th));}
double abs(const point &p) { return p.abs();}
double norm(const point &p) { return p.norm();}
double dot(const point &a, const point &b) { return a.dot(b);}
double cross(const point &a, const point &b) { return a.cross(b);}
double det(const point &a, const point &b) { return a.det(b);}
double arg(const point &a) { return a.arg();}
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

struct line
{
        point a, b;
        line(){}
        line(point a, point b):a(a),b(b){}

        point vec() const { return b-a;}
        double abs() const { return vec().abs();}
        double norm() const { return vec().norm();}
        point proj(const point &p) const { return a+vec().proj(p-a);}
        point refl(const point &p) const { return proj(p)*2-p;}
};
std::ostream &operator<<(std::ostream &os, const line &l) { os << l.a << " - " << l.b; return os; }

bool ill(const line &l, const line &m){ return std::abs(l.vec().det(m.vec())) > eps;}
bool ils(const line &l, const line &s){ return ccw(l.a,l.b,s.a)*ccw(l.a,l.b,s.b)<=0;}
bool isl(const line &s, const line &l){ return ils(l,s);}
bool iss(const line &s, const line &t){ return ils(s,t) and ils(t,s);}
point cll(const line &l, const line &m){ return l.a+l.vec()*(m.vec().det(m.a-l.a)/m.vec().det(l.vec()));}
double dlp(const line &l, const point &p){ return (l.proj(p)-p).abs();}
double dpl(const point &p, const line &l){ return dlp(l,p);}
double dll(const line &l, const line &m){ return ill(l,m) ? 0.0 : dlp(l,m.a);}
double dps(const point &p, const line &s){ return ccw(s.a,s.b,s.proj(p)) ? std::min((s.a-p).abs(), (s.b-p).abs()) : (s.proj(p)-p).abs();}
double dsp(const line &s, const point &p){ return dps(p,s);}
double dss(const line &s, const line &m){ return iss(s,m)? 0.0 : std::min(std::min(dps(m.a,s),dps(m.b,s)), std::min(dps(s.a,m),dps(s.b,m)));}

struct circle
{
        point o;
        double r;
        circle(){}
        circle(point o, double r) : o(o), r(r) {}
        circle(double r, point o) : o(o), r(r) {}
};
std::ostream &operator<<(std::ostream &os, const circle &c) { os << c.o << " - " << c.r; return os; }

int icc(const circle &c, const circle &d)
{
        /*
                    1 : intersect
                    0 : distinct
                    -1: c < d
                    -2: c > d
        */
        double od = (c.o-d.o).abs();
        return c.r+d.r<od+eps ? 0 : od+c.r<d.r+eps ? -1 : od+d.r<c.r+eps ? -2 : 1;
}

int icl(const circle &c, const line &l)
{
        /*
                    number of crosspoint
        */
        double d = (l.proj(c.o)-c.o).norm()-c.r*c.r;
        return d>eps ? 0 : std::abs(d)<eps ? 1 : 2;
}
int ilc(const line &l, const circle &c){ return icl(c,l);}
int ics(const circle &c, const line &s)
{
        /*
                    0 : distinct
                    1 : intersect 1 point
                    2 : s is in c
        */
        if (!icl(c, s)) return 0;
        double da = (s.a - c.o).abs();
        double db = (s.b - c.o).abs();
        if ((da < c.r-eps) and (db < c.r-eps)) return 0;
        if ((da < c.r-eps) xor (db < c.r-eps)) return 1;
        return ccw(s.a, s.b, s.proj(c.o)) ? 0 : 2;
}
int isc(const line &s, const circle &c) { return ics(c,s);}

double dcp(const circle &c, const point &p)
{
        double d = (c.o-p).abs();
        if(d < c.r+eps) return 0;
        return d-c.r;
}
double dpc(const point &p, const circle &c) { return dcp(c,p);}

double dcl(const circle &c, const line &l) { return std::max(dlp(l,c.o)-c.r,0.);}
double dlc(const line &l, const circle &c) { return dcl(c,l);}
double dcs(const circle &c, const line &s) { return std::max(dps(c.o,s)-c.r,0.);}
double dsc(const line &s, const circle &c) { return dcs(c,s);}

std::pair<point,point> ccl(const circle &c, const line &l)
{
        point h = l.proj(c.o), p = sqrt(c.r*c.r-(h-c.o).norm())*(l.b-l.a)/(l.b-l.a).abs();
        return std::pair<point,point>(h-p,h+p);
}
std::pair<point,point> clc(const line &l, const circle &c){ return ccl(c,l);}

std::pair<point,point> ccc(const circle &c1, const circle &c2)
{
        if(!icc(c1,c2)) return std::pair<point,point>(c1.o,c2.o);
        double w = (c2.o-c1.o).abs(), th = (c2.o-c1.o).arg();
        double dth = std::acos((c1.r*c1.r+w*w-c2.r*c2.r)/(2.*c1.r*w));
        return std::pair<point,point>(c1.o+D2::polar(c1.r,th-dth),c1.o+D2::polar(c1.r,th+dth));
}

line tangent(const circle &c, const double &th)
{
        point h = c.o+D2::polar(c.r,th);
        point p = D2::polar(c.r,th)*D2::point(0,1);
        return line(h-p,h+p);
}

std::vector<line> common_tangent(const circle &c, const circle &d)
{
        std::vector<line> ret;
        double dist = (d.o - c.o).abs(), th = (d.o - c.o).arg();
        if (std::abs(c.r - d.r) < dist) { // outer
                double dth = std::acos((c.r - d.r) / dist);
                ret.push_back(tangent(c, th - dth));
                ret.push_back(tangent(c, th + dth));
        }
        if (std::abs(c.r + d.r) < dist) {
                double dth = std::acos((c.r + d.r) / dist);
                ret.push_back(tangent(c, th - dth));
                ret.push_back(tangent(c, th + dth));
        }
        return ret;
}
}

using namespace D2;
using namespace std;

int n, w, h, r, vx, vy;
point s;
vector<circle> ps;

int solve()
{
}

bool input()
{
        scanf("%d", &n);
        if(!n) return 0;
        scanf("%d%d%d%d%d", &w, &h, &r, &vx, &vy);
        int x, y;
        scanf("%d%d", &x, &y);
        n--;
        s = point(x,y);
        ps.clear();
        for (int i = 0; i < n; i++) {
                scanf("%d%d", &x, &y);
                ps.push_back(circle(point(x,y), r));
        }
        return 1;
}

int main()
{
        while(input()) printf("%d\n", solve());
        return 0;
}
