#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef long long ll;

int p[8] = {1, 2, 3, 5, 7, 11, 13, 17};
bool used[10];
ll ans;

ll stoi(string str){
    stringstream s;
    s << str;
    ll ret;
    s >> ret;
    return ret;
}

string itos(ll n){
    stringstream s;
    s << n;
    string ret;
    s >> ret;
    return ret;
}

void subDiv(ll n){
    string d = itos(n);
    for(int i = 1; i < 8; i++){
	int td = stoi(d.substr(i,3));
	if(td % p[i] != 0){
	    return;
	}
    }
    ans += n;
    return;
}

void dfs(ll n){
    bool ok = true;
    for(int i = 0; i < 10; i++){
	if(!used[i]){
	    ok = false;
	    used[i] = true;
	    dfs(n*10+i);
	    used[i] = false;
	}
    }
    if(ok){
	subDiv(n);
    }
    return;
}

int main(){
    memset(used,0,sizeof(used));
    ans = 0;
    for(int i = 1; i < 10; i++){
	used[i] = true;
	dfs(i);
	used[i] = false;
    }
    cout << ans << endl;
}
