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

const int MAX = 1000000;

int main(){

    int prev = 13;
    int cnt = 0;
    repi(i,5,MAX+1){
        int next = prev + __gcd(i,prev);
//        cout << next << (i%20==0? '\n':'\t');
//        cout << i<<':'<<next << ':' << next - prev << (i%5==0? "\n":"\t\t");
        if(next - prev > 1) cout << ++cnt << ' ' << i << ' ' << next << ' ' << next - prev << endl;
        prev = next;
    }
    return 0;
}
