#include <bits/stdc++.h>

using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int di[] = {-1,-1,-1,0,1,1,1,0}, dj[] = {-1,0,1,1,1,0,-1,-1};

int h, w;
string f[1024];
pair<int,int> lt, lb, rt, rb;
inline bool in(int i, int j) { return i>=0 and i<h and j>=0 and j<w; }

void update(int i, int j) {
    if(lt.first > i) lt = make_pair(i,j);
    else if(lt.first == i and lt.second > j) lt = make_pair(i,j);
    if(lb.first < i) lb = make_pair(i,j);
    else if(lb.first == i and lb.second > j) lb = make_pair(i,j);
    if(rt.first > i) rt = make_pair(i,j);
    else if(rt.first == i and rt.second < j) rt = make_pair(i,j);
    if(rb.first < i) rb = make_pair(i,j);
    else if(rb.first == i and rb.second < j) rb = make_pair(i,j);
}

void dfs(int i, int j) {
    f[i][j] = ' ';
    update(i,j);
    rep(d,8) {
        const int ni = i+di[d], nj = j+dj[d];
        if(in(ni,nj) and f[ni][nj] == '*') dfs(ni,nj);
    }
}

void solve() {
    w = 0;
    rep(i,h) w = max(w, (int)f[i].size());
    rep(i,h) f[i].resize(w,' ');
    map<int,int> cnt;
    rep(i,h) rep(j,w) if(f[i][j] == '*') {
        lt = make_pair(1024, 1024);
        rt = make_pair(1024, -1);
        lb = make_pair(-1, 1024);
        rb = make_pair(-1, -1);
        dfs(i,j);
        if(lt.first == rt.first and lb.first == rb.first) cnt[((rt.second-lt.second)+(rb.second-lb.second)+2)*(lb.first-lt.first+1)/2]++;
        else cnt[((lb.first-lt.first)+(rb.first-rt.first)+2)*(rt.second-lt.second+1)/2]++;
    }
    for(auto &e: cnt) cout << e.first << ' ' << e.second << endl;
}

bool input() {
    cin >> h;
    cin.ignore();
    rep(i,h) getline(cin,f[i]);
    return h;
}

int main() {
    for(int t = 0; input(); t++) {
        if(t) cout << "----------" << endl;
        solve();
    }
    return 0;
}
