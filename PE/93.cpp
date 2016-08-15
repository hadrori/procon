#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;


class Rational {
    long long num, den;

protected:
    long long gcd(long long x, long long y);
    void reduce();
    void liftSign();
    void normalize();

public:
    Rational();
    ~Rational();
    Rational(const long long &num);
    Rational(const long long &num, const long long &den);

    static Rational arrayReader(const std::vector<long long> &array);

    Rational operator*=(const Rational &r);
    Rational operator*(const Rational &r) const;
    Rational operator/=(const Rational &r);
    Rational operator/(const Rational &r) const;
    Rational operator+=(const Rational &r);
    Rational operator+(const Rational &r) const;
    Rational operator-=(const Rational &r);
    Rational operator-(const Rational &r) const;
    bool operator<(const Rational &r) const;
    bool operator>(const Rational &r) const;
    bool operator<=(const Rational &r) const;
    bool operator>=(const Rational &r) const;
    bool operator==(const Rational &r) const;
    bool operator!=(const Rational &r) const;

    long long getNum();
    long long getDen();

    std::string toString() const;
    Rational inverse() const;
};

Rational::Rational() : num(0), den(1) {}
Rational::~Rational() {}
Rational::Rational(const long long &num) : num(num), den(1) {}
Rational::Rational(const long long &num, const long long &den) : num(num), den(den) { normalize(); }

// protected methods
long long Rational::gcd(long long x, long long y) {
    long long z;
    while(y) { z = y; y = x%y; x = z; }
    return x;
}

void Rational::reduce() {
    long long t = gcd(std::abs(num), den);
    num /= t; den /= t;
}

void Rational::liftSign() { if(den < 0) { num *= -1; den *= -1; } }

void Rational::normalize() {
    if(den == 0) throw std::range_error("zero division");
    if(den == LLONG_MIN or num == LLONG_MIN) throw std::underflow_error("LLONG_MIN");
    if(num == LLONG_MAX or num == -LLONG_MAX) { den = 1; return; }
    if(num == 0) { den = 1; return; }
    liftSign();
    reduce();
}

// public methods
Rational Rational::arrayReader(const std::vector<long long> &array) {
    if((int)array.size() == 1) return Rational(array[0]);
    if((int)array.size() == 2) return Rational(array[0],array[1]);
    throw std::length_error("length of array was not 1 nor 2");
}

Rational Rational::operator*=(const Rational &r) {
    long long t = gcd(den,std::abs(r.num)), u = gcd(r.den,std::abs(num));
    num = num/u*r.num/t;
    den = den/t*r.den/u;
    return *this;
}

Rational Rational::operator*(const Rational &r) const { return Rational(*this) *= r; }

Rational Rational::operator/=(const Rational &r) {
    if(r.num == 0) throw std::range_error("zero division");
    return Rational(*this) *= Rational(r.den,r.num);
}
Rational Rational::operator/(const Rational &r) const { return Rational(*this) /= r; }
Rational Rational::operator+=(const Rational &r) {
    long long t = gcd(den,r.den);
    num = r.den/t*num+den/t*r.num;
    den = den/t*r.den;
    normalize();
    return *this;
}
Rational Rational::operator+(const Rational &r) const { return Rational(*this) += r; }
Rational Rational::operator-=(const Rational &r) { return *this += Rational(-1)*r; }
Rational Rational::operator-(const Rational &r) const { return Rational(*this) -= r; }
bool Rational::operator<(const Rational &r) const {
    if(num == -LLONG_MAX or r.num == LLONG_MAX) return true;
    if(num == LLONG_MAX or r.num == -LLONG_MAX) return false;
    return num*r.den < den*r.num;
}
bool Rational::operator>(const Rational &r) const {
    if(num == -LLONG_MAX or r.num == LLONG_MAX) return false;
    if(num == LLONG_MAX or r.num == -LLONG_MAX) return true;
    return num*r.den > den*r.num;
}
bool Rational::operator<=(const Rational &r) const { return !((*this) > r); }
bool Rational::operator>=(const Rational &r) const { return !((*this) < r); }
bool Rational::operator==(const Rational &r) const { return num == r.num and den == r.den; }
bool Rational::operator!=(const Rational &r) const { return !((*this) == r); }

// for api
long long Rational::getNum() { return num; }
long long Rational::getDen() { return den; }
std::string Rational::toString() const {
    if(num == LLONG_MAX) return "inf";
    if(num == -LLONG_MAX) return "-inf";
    if(den == 1) return std::to_string(num);
    return std::to_string(num)+"/"+std::to_string(den);
}
Rational Rational::inverse() const { return Rational(1)/(*this); }

const string ops = "+-*/";

Rational calc(Rational a, Rational b, char op) {
    switch(op) {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    default: return a/b;
    }
}

void solve() {
    int mn = 0, ans = 0;
    rep(a,10) repi(b,a+1,10) repi(c,b+1,10) repi(d,c+1,10) {
        int x = 1000*a+100*b+10*c+d;
        string s = to_string(x);
        vector<int> ex(7000);
        rep(i,4) rep(j,4) rep(k,4) {
            string t = s;
            t.push_back(ops[i]); t.push_back(ops[j]); t.push_back(ops[k]);
            do {
                stack<Rational> st;
                try {
                    for (auto &e: t) {
                        if(isdigit(e)) st.push(Rational(e-'0'));
                        else {
                            if(st.empty()) throw std::range_error("stack is empty");
                            Rational u = st.top(); st.pop();
                            if(st.empty()) throw std::range_error("stack is empty");
                            Rational v = st.top(); st.pop();
                            st.push(calc(u, v, e));
                        }
                    }
                    if(st.empty()) throw std::range_error("stack is empty");
                    Rational f = st.top();
                    if(f.getDen() == 1) ex[f.getNum()] = 1;
                } catch (exception e) {
                }
            } while(next_permutation(begin(t),end(t)));
        }
        int n = 0;
        repi(i,1,7000) {
            if(!ex[i]) break;
            n = i;
        }
        if(n > mn) { ans = x; mn = n; }
    }
    cout << "length : " << mn << endl;
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
