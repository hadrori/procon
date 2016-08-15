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

const int MAX = 100000000;
const int upper = 10000;

bool p[MAX];
vi prm;
void pcalc(){
    p[0] = p[1] = true;
    rep(i,MAX)if(!p[i]){
	prm.pb(i);
	for(int j = 2 * i; j < MAX; j+= i)p[j] = true;
    }
}

int ans;

bool isPP(int a, int b){
    int s = b * pow(10.0,(int)log10(a)+1) + a;
    int t = a * pow(10.0,(int)log10(b)+1) + b;
    return !p[s] && !p[t];
}

void rec(int cur, int k, int seq[]){
    rep(i,k-1)if(!isPP(seq[k-1],seq[i])) return;
    if(k == 5){
	int sum = 0;
	rep(i,5)sum += seq[i];
	ans = min(ans, sum);
	return;
    }
    if(ans < prm[cur]) return;
    for(int i = cur + 1; prm[i] < upper; i++){
	seq[k] = prm[i];
	rec(i,k+1,seq);
    }
}

int main(){
    pcalc();
    int seq[5] = {0};
    ans = INF;
    rec(0, 0, seq);
    cout << ans << endl;
    return 0;
}
