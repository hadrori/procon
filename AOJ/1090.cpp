#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int inf = 1e9;
int n, m, col[128], bad[16];
string s;

bool neg_cycle()
{
        int dist[128];
        dist[0] = 0;
        for (int i = 1; i < n; i++) dist[i] = inf;

        int _ = n+1;
        while(_--) {
                bool updated = 0;
                for (int i = 0; i < n; i++) {
                        for(auto &e: G[i]) {
                                if(dist[e.first] > dist[i] + e.second) {
                                        dist[e.first] = dist[i] + e.second;
                                        updated = 1;
                                }
                        }
                }
                if(!updated) return 0;
        }
        return 1;
}

void solve()
{
        if(neg_cycle()) {
                cout << -1 << endl;
                return;
        }
        for (int i = 0; i < (int)s.size(); i++) bad[i] = s[i]-'1';

}

void init()
{
        for (int i = 0; i < n; i++) G[i].clear();
}

bool input()
{
        cin >> n;
        if(!n) return 0;
        init();
        for (int i = 0; i < n; i++) {
                cin >> col[i];
                col[i]--;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
                int a, b, c;
                cin >> a >> b >> c;
                G[a-1].push_back(pii(b-1,c));
        }
        cin >> k >> s;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        while(input()) solve();
        return 0;
}
