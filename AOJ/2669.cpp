#include <bits/stdc++.h>
using namespace std;

const string v = "AZ";
string s;

string solve()
{
    string ret = "";
    int k = 0;
    for(auto &e: s) {
        if(e != v[k]) continue;
        ret.push_back(e);
        k ^= 1;
    }
    if(ret.size() and ret.back() == 'A') ret = ret.substr(0,ret.size()-1);
    if(ret.size()) return ret;
    return "-1";
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
