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

point cll(const line &l, const line &m){ return l.a+l.vec()*(m.vec().det(m.a-l.a)/m.vec().det(l.vec()));}
}

using namespace std;
using namespace D2;

int n;
point ps[16];
double len[16];

point calc(int i, int j)
{
        const double dd = (ps[j]-ps[i]).norm();
        return (ps[j]-ps[i])*(len[i]*len[i]-len[j]*len[j]+dd)/2/dd+ps[i];
}

double solve()
{
        double ans = 0;
        for (int i = 0; i < n; i++) {
                double res = len[i]*len[i];
                for (int j = 0; j < n; j++) res = min(res, len[j]*len[j]-(ps[i]-ps[j]).norm());
                ans = max(ans, sqrt(res));
        }
        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                        const point p = calc(i,j);
                        double res = len[i]*len[i]-(p-ps[i]).norm();
                        for (int k = 0; k < n; k++) res = min(res, len[k]*len[k]-(p-ps[k]).norm());
                        ans = max(ans, sqrt(res));
                }
        }

        for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                        point tp = calc(i,j);
                        const line s = line(tp, point(ps[j]-ps[i])*point(0,1)+calc(i,j));
                        for (int k = j+1; k < n; k++) {
                                tp = calc(i,k);
                                const line t = line(tp, point(ps[k]-ps[i])*point(0,1)+tp);
                                const point p = cll(s,t);
                                double res = len[i]*len[i]-(p-ps[i]).norm();
                                for (int a = 0; a < n; a++) res = min(res, len[a]*len[a]-(p-ps[a]).norm());
                                ans = max(ans, sqrt(res));
                        }
                }
        }

        return ans;
}

bool input()
{
        scanf("%d", &n);
        double x, y;
        for (int i = 0; i < n; i++) {
                scanf("%lf%lf%lf", &x, &y, len+i);
                ps[i] = point(x,y);
        }
        return n;
}

int main()
{
        while(input()) printf("%.7f\n", solve());
        return 0;
}

