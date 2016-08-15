#include <bits/stdc++.h>
using namespace std;

string s;

bool solve()
{
        int v = s[0]-'A';
        for (int i = 1; i < (int)s.size(); i++) {
                int w = s[i]-'A';
                if(w%3 and w-1 == v) v = w;
                else if(w%3<2 and w+1==v) v = w;
                else if(w/3 and w-3==v) v = w;
                else if(w/3<2 and w+3==v) v = w;
                else return 0;
                v = w;
        }
        return 1;
}

int main()
{
        int r = 1000;
        while(r--) {
                cin >> s;
                if(solve()) cout << s << endl;
        }
        return 0;
}
