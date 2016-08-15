#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1,-1,-1,0,1,1,1,0}, dj[] = {-1,0,1,1,1,0,-1,-1};

string f[32];
int h[32][32], n;

inline bool in(int i, int j) { return 0<=i and i<20 and 0<=j and j<17;}

set<int> done;

int solve()
{
        memset(h,0,sizeof(h));
        n = 0;
        int si = -1, sj = -1;
        for (int i = 0; i < 19; i++) {
                for (int j = 1; j <= 15; j++) {
                        if(f[i][j] == 'O') {
                                si = i;
                                sj = j;
                        }
                        else if(f[i][j] == 'X') h[i][j] = ++n;
                }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push(make_pair(0, si*21+sj));
        while(!q.empty()) {
                int st = q.top().second, d = q.top().first; q.pop();
                int i = st/21%21, j = st%21, s = st/441;
                if(i == 19 or (i == 18 and j and j < 16)) return d;
                if(!j or j == 16) continue;
                if(done.count(st)) continue;
                done.insert(st);

                for (int k = 0; k < 8; k++) {
                        int ni = i+di[k], nj = j+dj[k];
                        while(in(ni,nj) and h[ni][nj] and !(s>>h[ni][nj]&1)) {
                                ni += di[k];
                                nj += dj[k];
                        }

                        if(!in(ni,nj) or (ni == i+di[k] and nj == j+dj[k])) continue;
                        int pi = i+di[k], pj = j+dj[k], ns = s;
                        while(pi != ni or pj != nj) {
                                ns |= 1<<h[pi][pj];
                                pi += di[k];
                                pj += dj[k];
                        }
                        q.push(make_pair(d+1,ns*441+ni*21+nj));
                }
        }
        return -1;
}

void input()
{
        string s;
        for (int i = 0; i < 19; i++) {
                cin >> s;
                f[i] = "."+s+".";
        }
        f[19] = ".................";
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
