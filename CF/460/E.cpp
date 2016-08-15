#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
inline int sq(int x){ return x*x;}
const int dx[] = {0,0,0,-1,1,1,-1,-1,1,2,2,1,-1,-2};
const int dy[] = {0,1,-1,1,1,-1,-1,1,2,2,1,-1,-2,-2,-1};

int n, r;
vector<pii> cand[16];
vector<int> pos;

void rec(int k, int p)
{
        if(k == 1) {
                pos.push_back(p);
                return;
        }
        rec(k/2+k%2, 2*p+1);
        rec(k/2, 2*p+2);
}

void solve()
{
        for (int i = 1; i < 15; i++) {
                int x = 0, y = 0;
                while(sq(x)+sq(y)<=sq(r)) {
                        cand[i].push_back(pii(x,y));
                        x += dx[i];
                        y += dy[i];
                }
        }

        
        rec(n,0);
        int sum = -1;
        for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                        pos[i] = (pos[i]+1)%15;
                }

                int s = 0;
                for (int i = 0; i < n; i++) {
                        for (int j = i+1; j < n; j++) {
                                s += sq(cand[pos[i]].back().first-cand[pos[j]].back().first)+sq(cand[pos[i]].back().second-cand[pos[j]].back().second);
                        }
                }
                if(s > sum) {
                        sum = s;
                        ans.clear();
                        for (int i = 0; i < n; i++) ans.push_back(cand[pos[i]]);
                }
                                

        }

        cout << sum << endl;
        for (int i = 0; i < n; i++) {
                cout << ans[i].first << " " << ans[i].second << endl;
        }

}

void input()
{
        cin >> n >> r;
}

int main()
{
        input();
        solve();
        return 0;
}
