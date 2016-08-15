#include <bits/stdc++.h>
using namespace std;

const string t[] = {" ", "',.!?", "abcABC", "defDEF", "ghiGHI", "jklJKL", "mnoMNO", "pqrsPQRS", "tuvTUV", "wxyzWXYZ"};

string s;

string solve()
{
        string ret = "";
        int p = 0, n = s.size();
        while(p < n) {
                int cnt = -1;
                char c = s[p];
                while(p < n and s[p] == c and (c == '0' or s[p] != '0')) {
                        cnt++;
                        p++;
                }
                if(c != '0') ret.push_back(t[c-'0'][cnt%(t[c-'0'].size())]);
                else ret += string(cnt, ' ');
        }
        return ret;
}

int main()
{
        while(cin >> s) cout << solve() << endl;
        return 0;
}
