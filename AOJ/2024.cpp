#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

string s, t;

int calc() {
    int x = 114514, c = 0;
    rep(a,1<<4) {
        int k = 0, sum = 0, f = 0;
        rep(i,s.size()) {
            if(s[i] == 'A') {
                if(a>>k&1) {
                    sum += 11;
                    f = 1;
                    k++;
                }
                else sum++;
            }
            else if(isupper(s[i])) sum += 10;
            else sum += s[i]-'0';
        }
        if(x > 21) {
            x = sum;
            c = f;
        }
        else if(sum <= 21 and sum > x) {
            x = sum;
            c = f;
        }
    }
    return x*2+c;
}

string solve()
{
    if(calc()/2 == 21) return "blackjack";
    rep(i,8) {
        int c = calc();
        if(c/2 > 21) return "bust";
        if(c/2 <= 16 or (c/2 == 17 and c%2)) s.push_back(t[i]);
        else return to_string(c/2);
    }
    int c = calc();
    if(c/2 > 21) return "bust";
    return to_string(c/2);
}

void input()
{
    s = t = "";
    char a, b;
    cin >> a >> b;
    s.push_back(a);
    s.push_back(b);
    rep(i,8) {
        cin >> a;
        t.push_back(a);
    }
}

int main()
{
    int t; cin >> t;
    while(t--) {
        input();
        cout << solve() << endl;
    }
    return 0;
}
