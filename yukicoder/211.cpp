#include <bits/stdc++.h>
using namespace std;
string s;

int number(int &i) {
    int sig = 1, k = 0;
    if(!isdigit(s[i]))
        if(s[i++] == '-') sig = -1;
    while(i < s.size() and isdigit(s[i])) k = 10*k+s[i++]-'0';
    return sig*k;
}

int solve(int &i, int sum) {
    if(i == s.size()) return sum;
    if(s[i++] == '-') return solve(i,sum+number(i));
    else return solve(i,sum-number(i));
}

int main() {
    cin >> s;
    int i = 0;
    cout << solve(i,number(i)) << endl;
    return 0;
}
