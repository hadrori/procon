#include <bits/stdc++.h>
using namespace std;

string s, t;

string solve()
{
        string ans = "";
        if(t == "L" or t == "D") ans.push_back(tolower(s[0]));
        else ans.push_back(toupper(s[0]));

        for (int i = 1; i < (int)s.size(); i++) {
                if(s[i] == '_') {
                        if(t != "D") ans.push_back(toupper(s[i+1]));
                        else {
                                ans.push_back(s[i]);
                                ans.push_back(s[i+1]);
                        }
                        i++;
                }
                else if(isupper(s[i])) {
                        if(t != "D") ans.push_back(s[i]);
                        else {
                                ans.push_back('_');
                                ans.push_back(tolower(s[i]));
                        }
                }
                else ans.push_back(s[i]);
        }
        return ans;
}

bool input()
{
        cin >> s >> t;
        return t != "X";
}

int main()
{
        while(input()) cout << solve() << endl;
        return 0;
}
