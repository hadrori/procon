#include <bits/stdc++.h>
using namespace std;

struct event
{
        int i, j, c;
        event(int i, int j, int c) : i(i), j(j), c(c) {}
        bool operator<(const event &e) const {
                if(i*e.j == e.i*j) return c < e.c;
                return i*e.j < e.i*j;
        }
};

int h, w;
string f[610];
vector<event> es;

/*
  increase
  #.
  ..

  .#
  ##

  decrease
  ..
  .#

  ##
  #.
 */

int diff(int i, int j)
{
        if(i == 0) {
                if(f[i][j] == '#' and f[i][j+1] == '.') return 1;
                return 0;
        }
        if(i == h) {
                if(f[i-1][j] == '.' and f[i-1][j+1] == '#') return -1;
                return 0;
        }
        int ret = 0;
        if(f[i][j] == '#' and f[i-1][j] == '.' and f[i][j+1] == '.') ret++;
        if(f[i][j] == '.' and f[i-1][j] == '#' and f[i][j+1] == '#') ret++;
        if(f[i-1][j+1] == '#' and f[i-1][j] == '.' and f[i][j+1] == '.') ret--;
        if(f[i-1][j+1] == '.' and f[i-1][j] == '#' and f[i][j+1] == '#') ret--;
        return ret;
}

int solve()
{
        es.clear();
        for (int i = 0; i <= h; i++) {
                for (int j = 0; j < w; j++) {
                        const int c = diff(i, j);
                        if(c) es.push_back(event(i,j+1,c));
                }
        }
        sort(begin(es),end(es));
        int ans = 1, cur = 1;
        for(auto &e: es) {
                cur += e.c;
                ans = max(ans, cur);
        }
        return ans;
}

void input()
{
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
                cin >> f[h-i-1];
                f[h-i-1].push_back('.');
        }
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
