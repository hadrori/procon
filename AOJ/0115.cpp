#include <bits/stdc++.h>
using namespace std;

#define double long double

const double eps = 1e-8;
struct point
{
        double x, y, z;
        point(){}
        point(double x, double y, double z) : x(x), y(y), z(z) { normalize();}
        void normalize() { x = std::abs(x)<eps? 0: x; y = std::abs(y)<eps? 0: y; z = std::abs(z)<eps? 0: z;}
        point &operator+=(const point &p) { x += p.x; y += p.y; z += p.z; normalize(); return *this;}
        point &operator-=(const point &p) { x -= p.x; y -= p.y; z -= p.z; normalize(); return *this;}
        point &operator*=(const double &d) { x *= d; y *= d; z *= d; normalize(); return *this;}
        point &operator/=(const double &d) { x /= d; y /= d; z /= d; normalize(); return *this;}
        point operator+(const point &p) const { return point(*this) += p;}
        point operator-(const point &p) const { return point(*this) -= p;}
        point operator*(const double &d) const { return point(*this) *= d;}
        point operator/(const double &d) const { return point(*this) /= d;}
        double norm() const { return x*x+y*y+z*z;}
        double abs() const { return sqrt(norm());}
        double dot(const point &p) const { return x*p.x+y*p.y+z*p.z;}
        point vec() const { return (*this)/abs();}
        point cross(const point &p) const { return point(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);}
};

point operator*(const double &d, const point &p) { point q = p*d; return q;}
ostream &operator<<(ostream &os, const point &p) { os << "(" << p.x << "," << p.y << "," << p.z << ")"; return os;}
inline point det_vec(const point &a, const point &b, const point &c) { return (b-a).cross(c-a).vec();}

point p, q, a, b, c;

bool solve()
{
        const point n = det_vec(a,b,c);
        const point ph = n.dot(a-p)*n+p;
        const point qh = n.dot(a-q)*n+q;
        const point m = (ph-p).abs()/((ph-p).abs()+(qh-q).abs())*(q-p)+p;
        const point det1 = det_vec(a,b,m), det2 = det_vec(b,c,m), det3 = det_vec(c,a,m);

        if(abs(det1.dot(det2)-1) > eps or abs(det2.dot(det3)-1) > eps) return 0;

        const point s = m-p, t = q-p;
        
        if(abs(s.dot(t)-s.abs()*t.abs()) > eps) return 0;
        if(s.norm() > t.norm()+eps) return 0;
        return 1;
}

void input()
{
        double x, y, z;
        cin >> x >> y >> z;
        p = point(x,y,z);
        cin >> x >> y >> z;
        q = point(x,y,z);
        cin >> x >> y >> z;
        a = point(x,y,z);
        cin >> x >> y >> z;
        b = point(x,y,z);
        cin >> x >> y >> z;
        c = point(x,y,z);
}

int main()
{
        input();
        puts(solve()? "MISS": "HIT");
        return 0;
}
