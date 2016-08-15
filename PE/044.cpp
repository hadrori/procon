#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
const ll MAX = 1000000000;

bool p[MAX];
vector<ll> pent;

void genPent(){
    memset(p,false,sizeof(p));
    for(int i = 0; i*(3*i-1)/2 < MAX; i++){
	ll pnt = i * (3 * i - 1) / 2;
	pent.push_back(pnt);
	p[pnt] = true;
    }
    return;
}

int main(){
    genPent();
    ll d = MAX;
    for(int j = 1; j < pent.size(); j++){
	int k = j + 1;
	while(abs(pent[j] - pent[k]) < d && pent[k] + pent[j] < MAX && k < pent.size()){
	    if(p[pent[j] + pent[k]] && p[abs(pent[j] - pent[k])]){
		d = min(d, abs(pent[j]-pent[k]));
		break;
	    }
	    k++;
	}
    }
    cout << d << endl;
}
