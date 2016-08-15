#include <bits/stdc++.h>
using namespace std;
const string op = "+-*";

string s, t;

void bracket(int p)
{
        int l = p, r = p+1, d = 0;
do {
                l--;
                if(t[l] == ')') d++;
                if(t[l] == '(') d--;
        } while(d or (l > 0 and isdigit(t[l-1])));
        do {
                if(t[r] == '(') d++;
                if(t[r] == ')') d--;
                r++;
        } while(d or (r < (int)t.size() and isdigit(t[r])));
        t = t.substr(0,l)+"("+t.substr(l,r-l)+")"+t.substr(r);
}

long long number(int l, int r)
{
        long long ret = 0;
        while(l < r) ret = ret*10+t[l++]-'0';
        return ret;
}

long long calc(int l, int r)
{
        if(l >= r) return 0;
        if(isdigit(t[l])) return number(l,r);
        l++; r--;
        int m = l, d = 0;
        do {
                if(t[m] == '(') d++;
                if(t[m] == ')') d--;
                m++;
        } while(d or (m < r and isdigit(t[m])));
        long long a = calc(l,m), b = calc(m+1,r);
        if(t[m] == '-') return a-b;
        if(t[m] == '+') return a+b;
        if(t[m] == '*') return a*b;
        return a;
}

long long solve()
{
        long long ans = -LONG_MAX;
        for (int i = 0; i < 27; i++) {
                t = "("+s+")";
                int p[] = {i%3, i/3%3, i/9%3};
                for (int j = 0; j < 3; j++) {
                        for (int k = 0; k < (int)t.size(); k++) {
                                if(t[k] == '+' and p[0] == j) bracket(k++);
                                if(t[k] == '-' and p[1] == j) bracket(k++);
                                if(t[k] == '*' and p[2] == j) bracket(k++);
                        }
                }
                ans = max(ans, calc(0,t.size()));
        }
        return ans;
}

void input()
{
        cin >> s;
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
