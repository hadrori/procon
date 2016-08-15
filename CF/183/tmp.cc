#include <bits/stdc++.h>
using namespace std;
long long fib[1000010], dp[1000010];
int main(){
    fib[0] = 1; fib[1] = 1;
    for(int i = 2; fib[i-1] < 1000000; i++)
        fib[i] = fib[i-1]+fib[i-2];
    dp[0] = 1;
    for(int i = 2; fib[i] <= 1000000; i++)
        for(int j = 0; j+fib[i] <= 1000000; j++)
            dp[j+fib[i]] += dp[j];
    cout << dp[1000000] << endl;
}
