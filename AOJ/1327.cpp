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
const double EPS = 1e-8;
const double PI = acos(-1.0);

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;


int N, M, A, B, C, T;

typedef int number;
typedef vector<number> arr;
typedef vector<arr> mat;

//単位行列 O( n )
mat identity(int n) {
    mat A(n, arr(n));
    rep(i,n) A[i][i] = 1;
    return A;
}

//積 O( n^3 )
mat mul(const mat &A, const mat &B) {
    mat C(A.size(), arr(B[0].size()));
    rep(i,C.size()) rep(j,C[i].size()) rep(k,A[i].size())
        C[i][j] = (C[i][j]+A[i][k]*B[k][j]%M)%M;
    return C;
}

//累乗 O( n^3 log e )
mat pow(const mat &A, int e) {
    return e == 0 ? identity(A.size())  :
        e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}

int main(){
    while(cin>>N>>M>>A>>B>>C>>T,N){
        mat s = mat(1,arr(N));
        rep(i,N) cin >> s[0][i];
        mat t = mat(N,arr(N,0));
        rep(i,N){
            if(i > 0) t[i][i-1] = C;
            t[i][i] = B;
            if(i<N-1) t[i][i+1] = A;
        }
        s = mul(s,pow(t,T));
        rep(i,N) cout << s[0][i] << (i==N-1? '\n': ' ');
    }
    return 0;
}
