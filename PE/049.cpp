#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20000;
bool p[MAX];
vector<int> prime;

void pcalc(){
    for(int i = 0; i < MAX; i ++)
	p[i] = (i < 2)? false: true;
    for(int i = 0; i < MAX; i++){
	if(p[i]){
	    prime.push_back(i);
	    for(int j = 2 * i; j < MAX; j += i)
		p[j] = false;
	}
    }
    return;
}

bool isPerm(int a, int b){
    int cnta[10] = {0}, cntb[10] = {0};
    while(a){
	cnta[a%10]++;
	a /= 10;
    }
    while(b){
	cntb[b%10]++;
	b /= 10;
    }
    for(int i = 0; i < 10; i++)
	if(cnta[i] != cntb[i]) return false;
    return true;
}

int main(){
    pcalc();
    int cur = 0;
    while(prime[++cur] < 1000);
    
    while(prime[++cur] < 10000){
	bool ok = false;
	int curp = prime[cur];

	if(curp == 1487) continue;
	for(int i = cur + 1; prime[i] < 10000; i++){
	    if(isPerm(curp, prime[i])){
		int nxt = 2*prime[i] - curp;
		if(nxt > 10000) break;
		if(p[nxt] && isPerm(curp, nxt)){
		    ok = true;
		    cout << curp << prime[i] << nxt << endl;
		    break;
		}
	    }
	}
	if(ok)break;
    }
}
