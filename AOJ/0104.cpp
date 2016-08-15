#include <bits/stdc++.h>
using namespace std;
const string dir = ">v<^";
const int di[] = {0,1,0,-1}, dj[] = {1,0,-1,0};

int h, w;
vector<string> f;
vector<vector<int>> done;

void solve()
{
        done.assign(h,vector<int>(w,0));
        int i = 0, j = 0;
        while(!done[i][j] and f[i][j] != '.') {
                done[i][j] = 1;
                int d = dir.find(f[i][j]);
                i += di[d];
                j += dj[d];
        }
        if(done[i][j]) cout << "LOOP" << endl;
        else cout << j << " " << i << endl;
}

bool input()
{
        cin >> h >> w;
        if(!h and !w) return 0;
        string s;
        f.clear();
        for (int i = 0; i < h; i++) {
                cin >> s;
                f.push_back(s);
        }
        return 1;
}

int main()
{
        while(input()) solve();
        return 0;
}
