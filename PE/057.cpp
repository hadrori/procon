#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

string stringplus(string n, string m){
    string ret = "";
    int c = 0;
    for(int i = 0; i < n.size() || i < m.size(); i++){
	if(i < n.size() && i < m.size()){
	    int t = n[n.size()-1-i] - '0' + m[m.size()-1-i] - '0' + c;
	    if(t / 10) c = 1;
	    else c = 0;
	    t %= 10;
	    ret.push_back(t + '0');
	}else if(i < n.size()){
	    int t = n[n.size()-1-i] - '0' + c;
	    if(t / 10) c = 1;
	    else c = 0;
	    t %= 10;
	    ret.push_back(t + '0');
	}else if(i < m.size()){
	    int t = m[m.size()-1-i] - '0' + c;
	    if(t / 10) c = 1;
	    else c = 0;
	    t %= 10;
	    ret.push_back(t + '0');
	}
    }
    if(c) ret.push_back('1');
    reverse(ret.begin(), ret.end());
//    cerr << ret << endl;
    return ret;
}

int main(){
    int ans = 0;
    string prevn = "3", prevd = "2";
    for(int i = 1; i < 1000; i++){
	string num = stringplus(stringplus(prevd,prevd),  prevn);
	string den = stringplus(prevd, prevn);
//	cerr << num << " / " << den << endl;
	if(num.size() > den.size())ans++;
	prevd = den;
	prevn = num;
    }
    cout << ans << endl;
}
