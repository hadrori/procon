#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int ans = 0;
    for(int n = 1; ; n++){
	bool done = false;
	for(int x = 1; n >= (int)(n * log10(x)) + 1; x++)
	    if(n == (int)(n * log10(x)) + 1) {
		ans++;
		done = true;
	    }
	if(!done){
	    cout << ans << endl;
	    break;
	}
    }
    return 0;
}
