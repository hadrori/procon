#include <bits/stdc++.h>
using namespace std;

inline bool in(const string &s, const char &c) { return s.find(c) != string::npos;}

int n, f[128];
char s[128];

bool musei_siin(int i)
{
        const string ms = "ksthp";
        bool f = in(ms,s[i]);
        if(!i) return f;
        return f | (in(ms,s[i-1]) and s[i] == 'y');
}

void solve()
{
        n = strlen(s);
        memset(f,0,sizeof(f));
        bool sw = 1;
        for (int i = 0; i < n; i++) {
                if(s[i] == 'i' or s[i] == 'u') {
                        if(t and i and ) {
                                t = 0;
                        }
                        else t = 1;
                }
                if(s[i] == 'a' or s[i] == 'o') {
                        
                }
                if(s[i] == 'e') sw = 1;
        }
}

bool input()
{
        scanf("%s", s);
        return s[0] != "#";
}

int main()
{
        while(input()) solve();
        return 0;
}
