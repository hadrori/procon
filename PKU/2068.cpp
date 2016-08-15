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
typedef complex<double> P;
typedef vector<P> G;

int n, S;
int M[21];

int main(){
    while(scanf("%d", &n), n){
        scanf("%d", &S);
        rep(i,2*n) scanf("%d", M+i);
        int dp[21][(1<<13)+1] = {-1};
        repi(j, 1, S+1)
            rep(i, 2*n)
                if(j == 1) dp[i][j] = 0;
                else{
                    repi(k, 1, M[i]+1)
                        if(j - k < 1) break;
                        else if(dp[(i+1)%(2*n)][j-k] == 0)
                            dp[i][j] = 1;
                    if(dp[i][j] == -1) dp[i][j] = 0;
                }
        printf("%d\n", dp[0][S]);
    }
    return 0;
}
