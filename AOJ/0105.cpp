#include <bits/stdc++.h>
using namespace std;

map<string, vector<int>> f;

void solve()
{
        for(auto &vs: f) {
                cout << vs.first << endl;
                sort(begin(vs.second),end(vs.second));
                for (int i = 0; i < (int)vs.second.size(); i++)
                        cout << vs.second[i] << (i<vs.second.size()-1? " ": "\n");
        }
}

void input()
{
        string s;
        int p;
        while(cin >> s >> p) f[s].push_back(p);
}

int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        input();
        solve();
        return 0;
}

