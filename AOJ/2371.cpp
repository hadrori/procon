#include <bits/stdc++.h>
using namespace std;

struct node
{
        int v, d, c;
        node(){}
        node(int v, int d, int c) : v(v), d(d), c(c) {}

        bool operator<(const node &n) const {
                if(d != n.d) return d > n.d;
                return c > n.c;
        }
};

int n, t, g, idx1, idx2, rid[100010], done[100010], used[100010];
string from, to;
map<string,int> id;
vector<int> vs[100010];
vector<pair<int,int>> G[100010];

void solve()
{
        priority_queue<node> q;
        for(auto &e: vs[id[from]]) q.push(node(e,0,0));
        g = id[to];
        while(!q.empty()) {
                node k = q.top(); q.pop();
                if(done[k.v]) continue;
                done[k.v] = 1;
                if(rid[k.v] == g) {
                        cout << k.d << ' ' << k.c << endl;
                        return;
                }
                if(used[rid[k.v]]) for(auto &e: G[k.v]) q.push(node(e.first, k.d+e.second, k.c));
                else {
                        used[rid[k.v]] = 1;
                        for(auto &u: vs[rid[k.v]]) {
                                const int dd = (u == k.v)? 0: t, cd = (u == k.v)? 0: 1;
                                for(auto &e: G[u]) q.push(node(e.first, k.d+e.second+dd, k.c+cd));
                        }
                }
        }
        cout << -1 << endl;
}

void input()
{
        cin >> n >> t;
        cin >> from >> to;
        string s;
        for (int i = 0; i < n; i++) {
                int a; cin >> a;
                vector<int> tmp;
                for (int j = 0; j < a; j++) {
                        cin >> s;
                        if(!id.count(s)) id[s] = idx1++;
                        rid[idx2] = id[s];
                        vs[id[s]].push_back(idx2);
                        tmp.push_back(idx2++);
                }
                int d;
                for (int j = 0; j < a-1; j++) {
                        cin >> d;
                        G[tmp[j]].push_back(make_pair(tmp[j+1], d));
                        G[tmp[j+1]].push_back(make_pair(tmp[j], d));
                }
        }
}

int main()
{
        input();
        solve();
        return 0;
}
