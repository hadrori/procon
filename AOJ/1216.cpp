#include <bits/stdc++.h>

namespace D3 {
const double eps = 1e-4;

struct point
{
    double x, y, z;
    point(){}
    point(double x, double y, double z) : x(x), y(y), z(z) {}
    double norm() const { return x*x+y*y+z*z; }
    double abs() const { return std::sqrt(norm()); }
    double dot(const point &p) const { return x*p.x+y*p.y+z*p.z; }
    point cross(const point &p) const { return point(y*p.z, z*p.x, x*p.y); }

    point operator*=(const double &k) { x*=k;y*=k;z*=k; return (*this); }
    point operator*(const double &k) const { return point(*this)*=k; }
    point operator+=(const point &p) { x+=p.x;y+=p.y;z+=p.z; return (*this); }
    point operator+(const point &p) const { return point(*this)+=p; }
    point operator-=(const point &p) { x-=p.x;y-=p.y;z-=p.z; return (*this); }
    point operator-(const point &p) const { return point(*this)-=p; }
};
std::ostream &operator<<(std::ostream &o, const point &p) { o << '(' << p.x << ',' << p.y << ',' << p.z << ')'; return o;}
}

using namespace std;
using namespace D3;

#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int n;
double as[3];
vector<point> ps;

void solve() {
    rep(i,n) rep(j,n) rep(k,n) {
        if(i == j or j == k or k == i) continue;
        double ds[3];
        ds[0] = (ps[i]-ps[j]).abs();
        ds[1] = (ps[i]-ps[k]).abs();
        ds[2] = (ps[k]-ps[j]).abs();
        double x = ds[2]/as[2];
        if(abs(ds[0]/as[0]-x) < eps and abs(ds[1]/as[1]-x) < eps) {
            cout << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
            return;
        }
    }
}

void input() {
    cin >> as[2] >> as[1] >> as[0];
    cin >> n;
    ps.clear();
    double x, y, z;
    rep(i,n) {
        cin >> x >> y >> z;
        ps.push_back(point(x,y,z));
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    while(t--) {
        input();
        solve();
    }
    return 0;
}
