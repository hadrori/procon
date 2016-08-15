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

const int MAX = 1000000;

bool p[MAX];
vi prm;
void pcalc(){
    p[0] = p[1] = true;
    rep(i,MAX)if(!p[i]){
	prm.pb(i);
	for(int j = i * 2; j < MAX; j += i)
	    p[j] = true;
    }
}

string itos(int n){
    string ret;
    stringstream s;
    s << n;
    s >> ret;
    return ret;
}

int stoi(string str){
    int ret;
    stringstream s;
    s << str;
    s >> ret;
    return ret;
}

bool isAns(string num, char ini){
    int s = ini - '0' + 1;
    int cnt = 1;
    bool did = false;
    repi(i,s,10){
	string str = num;
	rep(j,num.size())
	    if(str[j] == '*'){
		str[j] = i + '0';
		did = true;
	    }
	int t = stoi(str);
	if(!p[t]) cnt++;
    }
    return did && cnt == 8;
}
bool rec(string num, int cur, char ini){
    if(cur == num.size()-1) return isAns(num, ini);
    if(num[cur] != ini) return rec(num, cur+1, ini);
    bool ret = false;
    ret |= rec(num, cur+1, ini);
    num[cur] = '*';
    ret |= rec(num, cur+1, ini);
    return ret;
}

int main(){
    pcalc();
    rep(i,prm.size()){
	rep(j,3){
	    int cnt = 0, t = prm[i];
	    while(t){
		if(t%10 == j) cnt++;
		t /= 10;
	    }
	    if(cnt && rec(itos(prm[i]),0, j + '0')){
		cout << prm[i] << endl;
		return 0;
	    }
	}
    }
    return 0;
}
