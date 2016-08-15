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

const int MAX = 100000;

bool p[MAX+1];
vi primes;

void prime_sieve(){
    memset(p,-1,sizeof(p));
    p[0] = p[1] = false;
    primes.pb(2);
    for(int j = 4; j < MAX + 1; j += 2) p[j] = false;
    for(int i = 3; i < MAX; i += 2)if(p[i]){
	    primes.pb(i);
	    for(int j = i * 2; j < MAX + 1; j += i)
		p[j] = false;
    }
}

int main(){
    prime_sieve();
    vector<pii> rad;
    rad.pb(pii(1,1));
    repi(i,2,MAX+1){
	cerr << i << endl;
	if(p[i]) rad.pb(pii(i,i));
	else{
	    int prd = 1;
	    int n = i;
	    for(int j = 0; n != 1; j++)
		if(i % primes[j] == 0){
		    prd *= primes[j];
		    while(n % primes[j] == 0) n /= primes[j];
		}
	    rad.pb(pii(prd,i));
	}
    }
    sort(all(rad));
    cout << rad[9999].second << endl;
    return 0;
}
