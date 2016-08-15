#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;

const int mod = 1e9+7;
struct mint{
    int x;
    mint():x(0){}
    mint(int y){ if((x=y%mod+mod) >= mod) x-= mod;}
    
    mint &operator+=(const mint &m){ if((x += m.x) >= mod) x-=mod; return *this;}
    mint &operator-=(const mint &m){ if((x += mod-m.x) >= mod) x-=mod; return *this;}
    mint &operator*=(const mint &m){ x = 1LL*x*m.x%mod; return *this;}
    mint &operator/=(const mint &m){ x=(1LL*x*ex(m,mod-2).x)%mod; return *this;}
    mint operator+(const mint &m)const{ return mint(*this) += m;}
    mint operator-(const mint &m)const{ return mint(*this) -= m;}
    mint operator*(const mint &m)const{ return mint(*this) *= m;}
    mint operator/(const mint &m)const{ return mint(*this) /= m;}    
    bool operator<(const mint &m)const{ return x < m.x;}
    bool operator>(const mint &m)const{ return x > m.x;}
    bool operator==(const mint &m)const{ return x == m.x;}
    bool operator&&(const mint &m)const{ return x && m.x;}
    bool operator||(const mint &m)const{ return x || m.x;}
    mint ex(mint a, long long t){
        if(!t) return 1;
        mint res = ex(a,t/2);
        res *= res;
        return (t&1)?res*a:res;
    }
};
ostream &operator<<(ostream& os, const mint &m){ os << m.x; return os;}

int n, f[32];

mint solve(){
    rep(S,1<<n){
        
    }
    return 0;
}

void input(){
    cin >> n;
    rep(i,n) cin >> f[i];
}

signed main(){
    cin.sync_with_stdio(0);
    input();
    cout << solve() << endl;
    return 0;
}
