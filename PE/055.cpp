#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

typedef long long ll;
const ll MAX = 10000;

string stringplus(string n, string m){ //長さは同じ
    string ret = "";
    int c = 0;
    for(int l = n.size()-1; l >= 0; l--){
	int a = n[l] - '0', b = m[l] - '0';
	int r = a + b + c;
	if(r >= 10) c = 1;
	else c = 0;
	r %= 10;
	ret.push_back(r+'0');
    }
    if(c) ret.push_back('1');
    reverse(ret.begin(),ret.end());
    return ret;
}

bool isPal(string n){
    int l = 0, r = n.size()-1;
    while(l < r){
	if(n[l] != n[r]) return false;
	l++;
	r--;
    }
    return true;
}

bool rec(string n, ll k){
//    cerr << n << endl;
    if(k >= 50) return false;
    string m = n;
    reverse(m.begin(), m.end());
    string z = stringplus(n,m);
    while(z[0] == '0') z.erase(z.begin());
    if(isPal(z)) return true;
    return rec(z,k+1);
}

int main(){
    ll ans = 0;
    for(ll i = 0; i < MAX; i++){
	stringstream s;
	s << i;
	string n;
	s >> n;
	if(!rec(n, 0))ans++;
    }
    cout << ans << endl;
}
