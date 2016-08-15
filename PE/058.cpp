#include <iostream>

using namespace std;
typedef long long ll;

const int MAX = 1000000000;
ll d[] = {2, 4, 6, 8};
bool p[MAX];

void pcalc(){
    for(int i = 0; i < MAX; i++)
	p[i] = (i < 2)? false: true;
    for(int i = 0; i * i < MAX; i++)
	if(p[i])for(int j = i * 2; j < MAX; j += i)
		    p[j] = false;
    return;
}

int main(){
    pcalc();
    ll diff = 0, dcnt = 1, pcnt = 0;
    ll diag[] = {1, 1, 1, 1};
    while(1){
	diff += 8;
	for(int i = 0; i < 4; i++){
	    diag[i] += d[i];
	    if(p[diag[i]]){
		pcnt++;
		cerr << diag[i] << endl;
	    }
	}
	dcnt += 4;
//	cerr << pcnt << ' ' << dcnt << endl;
	if(1.0*pcnt/dcnt < 0.1){
	    cout << diag[1] - diag[0] + 1 << endl;
	    break;
	}
	for(int i = 0; i < 4; i++) d[i] += 8;
    }
    return 0;
}
