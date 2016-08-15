#include <iostream>

using namespace std;

const int MAX = 10000000;

int memo[2*MAX];

int rec(int n){
    if(memo[n] >= 0) return memo[n];
    if(n == 89) return memo[n] = 1;
    if(n == 1) return memo[n] = 0;
    int nxt = 0, tmp = n;
    while(tmp){
	nxt += (tmp%10)*(tmp%10);
	tmp /= 10;
    }
    return memo[n] = rec(nxt);
}

int main(){
    int ans = 0;
    memset(memo, -1, sizeof(memo));
    for(int i = 1; i < MAX; i++)
	if(rec(i)) ans++;
    cout << ans << endl;
    return 0;
}
