#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;

bool p[MAX];
vector<int> prime;

void pcalc(){
    for(int i = 0; i < MAX; i++)
	p[i] = (i < 2)? false: true;
    for(int i = 0; i < MAX; i++){
	if(p[i]){
	    prime.push_back(i);
	    for(int j = i * 2; j < MAX; j += i)p[j] = false;
	}
    }
    return;
}

int main(){
    pcalc();
    for(int i = 9; i < MAX; i++){
	if(i % 2 == 1 && !p[i]){
	    bool ok = false;
	    for(int j = 1; prime[j] < i; j++){
		int t = i - prime[j];
		for(int k = 1; 2 * k * k <= t; k++){
		    if(2*k*k == t){
			ok = true;
			break;
		    }
		}
		if(ok)break;
	    }
	    if(!ok){
		cout << i << endl;
		break;
	    }
	}
    }
}
