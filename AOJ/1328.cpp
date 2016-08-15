#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
const int INF = 1e9;
const double EPS = 1e-5;
const double PI = acos(-1.0);
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
 
 
typedef double number;
typedef vector<number> arr;
typedef vector<arr> mat;
 
vector<double> v;
 
 
#define mkrot(x,y,c,s) {double r = sqrt(x*x+y*y); c = x/r; s = y/r;}
#define rot(x,y,c,s) {double u = c*x+s*y; double v = -s*x+c*y; x = u; y = v;}
arr givens(mat &A, arr b){
    int n = b.size();
    rep(i,n) repi(j,i+1,n){
        double c, s;
        mkrot(A[i][i], A[j][i], c, s);
        rot(b[i], b[j], c, s);
        repi(k,i,n) rot(A[i][k],A[j][k],c,s);
    }
    repd(i,n-1,0){
        repi(j,i+1,n)
            b[i] -= A[i][j] * b[j];
        b[i] /= A[i][i];
    }
    return b;
}
 
int d;
 
arr solve_eq(int m, int n){
    mat A(d+1,arr(d+1));
    arr b(d+1);
    int cnt = 0;
    rep(i,d+3)if(i != m && i != n){
        b[cnt] = v[i];
        rep(j,d+1) A[cnt][j] = pow(1.0*i,1.0*j);
        cnt++;
    }
    return givens(A,b);
}
 
int main(){
    while(cin >> d, d){
        v.resize(d+3);
        int ans = -1;
        rep(i,d+3) cin >> v[i];
        rep(i,d+3){
            repi(j,i+1,d+3){
                arr b = solve_eq(i,j);
                double e = 0, f = 0;
                rep(k,d+1) e += pow(1.0*i,1.0*k) * b[k];
                rep(k,d+1) f += pow(1.0*j,1.0*k) * b[k];
                if(abs(e-v[i]) > EPS && abs(f-v[j]) < EPS){
                    ans = i;
                    break;
                }
                if(abs(e-v[i]) < EPS && abs(f-v[j]) > EPS){
                    ans = j;
                    break;
                }
            }
            if(ans >= 0) break;
        }
        cout << ans << endl;
    }
    return 0;
}
