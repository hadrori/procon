#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

struct edge { int to, d, id; };

int n, m, mx, tmx, done[32], sum;
vector<edge> g[16];
vector<int> av, tav, seq;

vector<int> min_v(vector<int> a, vector<int> b) {
    rep(i,min(a.size(), b.size())) if(a[i] != b[i]) {
        if(a[i] < b[i]) return a;
        else return b;
    }
    if(a.size() < b.size()) return a;
    if(b.size() < a.size()) return b;
    return a;
}

void update() {
    if(tmx > sum) return;
    if(tmx < sum) {
        tmx = sum;
        tav = seq;
    }
    else tav = min_v(tav, seq);
}

void dfs(int v) {
    update();
    rep(i,g[v].size()) if(!done[g[v][i].id]) {
        seq.push_back(g[v][i].to);
        sum += g[v][i].d;
        done[g[v][i].id] = 1;

        dfs(g[v][i].to);

        seq.pop_back();
        sum -= g[v][i].d;
        done[g[v][i].id] = 0;
    }
}

void solve() {
    mx = 0;
    rep(i,n) {
        tmx = sum = 0;
        tav = {INT_MAX};
        seq = {i};
        dfs(i);
        if(mx < tmx) {
            av = tav;
            mx = tmx;
        }
        else if(mx == tmx) av = min_v(av, tav);
    }
    cout << mx << endl;
    rep(i,av.size()) cout << av[i]+1 << (i < (int)av.size()-1 ? ' ': '\n');
}

bool input() {
    rep(i,16) g[i].clear();
    cin >> n >> m;
    if(!n and !m) return 0;
    int a, b, c;
    rep(i,m) {
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back((edge){b,c,i});
        g[b].push_back((edge){a,c,i});
    }
    return 1;
}

int main() {
    while(input()) solve();
    return 0;
}
