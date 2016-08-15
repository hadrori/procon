#include <iostream>
#include <cmath>

using namespace std;

int num;

bool per_mul(int n){
    int ncnt[10] = {0};
    int numcnt[10] = {0};
    int tmp = num;
    while(tmp){
	numcnt[tmp%10]++;
	tmp /= 10;
    }
    tmp = n;
    while(tmp){
	ncnt[tmp%10]++;
	tmp /= 10;
    }
    for(int i = 0; i < 10; i++){
	if(ncnt[i] != numcnt[i]) return false;
    }
    return true;
}

int main(){
    num = 0;
    while(1){
	num++;
	bool ok = true;
	for(int i = 1; i < 7; i++){
	    if((int)log10(i*num) > (int)log10(num)){
		num = pow(10.0,(double)(int)log10(i*num));
		ok = false;
		break;
	    }
	    if(!per_mul(i*num)){
		ok = false;
		break;
	    }
	}
	if(ok){
	    cout << num << endl;
	    break;
	}
    }
}
