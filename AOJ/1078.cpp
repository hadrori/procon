#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> ss;
vector<vector<string>> sss;

bool solve()
{
        ss.clear();
        sss.clear();
        string tmp = "";
        for(auto &c: s) {
                if(c != '|') tmp.push_back(c);
                else {
                        tmp = tmp.substr(1,tmp.size()-2);
                        ss.push_back(tmp);
                        tmp = "";
                }
        }
        tmp = tmp.substr(1,tmp.size()-2);
        ss.push_back(tmp);
        for(auto &e: ss) {
                vector<string> t;
                tmp = "";
                for(auto &c: e) {
                        if(c != '&') tmp.push_back(c);
                        else {
                                t.push_back(tmp);
                                tmp = "";
                        }
                }
                t.push_back(tmp);
                sss.push_back(t);
        }
        for(auto &e: sss) {
                int f[256] = {};
                set<int> ssss;
                for(auto &g: e) {
                        if(g.size() > 1) f[g[1]] |= 2, ssss.insert(g[1]);
                        else f[g[0]] |= 1, ssss.insert(g[0]);
                }
                bool ok = 1;
                for(auto &g: ssss) {
                        if(f[g] == 3) ok = 0;
                }
                if(ok) return 1;
        }
        return 0;
}

bool input()
{
        cin >> s;
        return s != "#";
}

int main()
{
        while(input()) puts(solve()? "yes": "no");
        return 0;
}
