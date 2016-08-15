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
typedef pair<ll,ll> pii;
typedef complex<double> P;
typedef vector<P> G;

const int MAX = 100000;

ll stoi(string num){
    ll ret;
    stringstream s;
    s << num;
    s >> ret;
    return ret;
}

string itos(ll num){
    string ret;
    stringstream s;
    s << num;
    s >> ret;
    return ret;
}
int main(){
    map<ll, pii> table;
    for(ll i = 0; i < MAX; i++){
	ll t = i * i * i;
	if(t < 0) cerr << "fuck" << endl;
	string tmp = itos(t);
	sort(rall(tmp));
	t = stoi(tmp);
	if(t == 1) continue;
	map<ll,pii>::iterator itr = table.find(t);
	if(itr == table.end()) table[t] = mp(1,i);
	else (*itr).second.first++;
    }
    ll ans = INF;
    repit(itr,table)
	if((*itr).second.first == 5) ans = min(ans, (*itr).second.second);
    cout << ans * ans * ans << endl;
	
    return 0;
}
