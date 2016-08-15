#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

bool larger(string a, string b){
    if(a.size() > b.size()) return true;
    if(a.size() < b.size()) return false;
    return a > b;
}

int main(){
    int v;
    int a[10] = {0};
    cin >> v;
    bool exist = false;
    rep(i,9){
        cin >> a[i+1];
        if(a[i+1] <= v) exist = true;
    }
    if(!exist){
        cout << -1 << endl;
        return 0;
    }
    string dp[1000010];
    rep(i,v+1) dp[i] = "";
    repi(i,1,10){
        for(int j = a[i]; j <= v; j++){
            int ub = 0, lb = dp[j-a[i]].size()+1;
            while(lb - 1 > ub){
                int mid = (lb + ub) / 2;
                if(dp[j-a[i]][mid] - '0' > i) ub = mid;
                else lb = mid;
            }
            string tmp = dp[j-a[i]];
            string hoge = "";
            hoge += char(i+'0');
            tmp.insert(ub,hoge);
            if(larger(tmp,dp[j]))
                dp[j] = tmp;
//            cerr << dp[j] << endl;
        }
    }
    cout << dp[v] << endl;
    return 0;
}
