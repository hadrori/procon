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
    int mina = INF, pos;
    rep(i,9){
        cin >> a[i+1];
        if(mina >= a[i+1]){
            mina = a[i+1];
            pos = i + 1;
        }
    }
    if(mina > v){
        cout << -1 << endl;
        return 0;
    }
    int m = v / mina;
    v %= mina;
    string ans = "";
    rep(i,m)repd(j,9,1){
        if(v + mina - a[j] >= 0){
            v += mina - a[j];
            ans += j + '0';
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
