#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

struct event {
    int e, id, id2, t;
    event(int e, int id, int id2, int t) : e(e), id(id), id2(id2), t(t) {}
    bool operator<(const event &v) const {
        if(t == v.t) {
            if(e == v.e) return id > v.id;
            return e < v.e;
        }
        return t > v.t;
    }
};

int n, m, f[128], t[128], done[128];

void solve() {
    memset(t,-1,sizeof(t));
    memset(done,0,sizeof(done));
    vector<int> ans;
    queue<int> q;
    stack<pair<int,int>> s[16]; // id, time
    priority_queue<event> es;
    rep(i,n) es.push(event(0,i,-1,10*i));
    while(!es.empty()) {
        auto e = es.top(); es.pop();
        if(e.e) {
            if(done[e.id2]) continue;
            if(s[e.id].empty() or s[e.id].top().first != e.id2) continue;
            done[e.id2] = 1;
            ans.push_back(e.id2);
            s[e.id].pop();
            if(s[e.id].size() and s[e.id].top().second <= e.t) {
                done[s[e.id].top().first] = 1;
                ans.push_back(s[e.id].top().first);
                s[e.id].pop();
            }
            while(q.size() and s[e.id].size() < 2) {
                s[e.id].push(make_pair(q.front(), e.t+f[q.front()]));
                es.push(event(1,e.id,q.front(),e.t+f[q.front()]));
                q.pop();
            }
        }
        else {
            bool zr = 0;
            rep(i,m) if(s[i].empty()) {
                zr = 1;
                s[i].push(make_pair(e.id,e.t+f[e.id]));
                es.push(event(1,i,e.id,e.t+f[e.id]));
                break;
            }
            if(!zr) {
                int dif = 1e9, id = -1;
                rep(i,m) if(s[i].size() == 1) {
                    if(s[i].top().second >= e.t+f[e.id] and dif > s[i].top().second-e.t-f[e.id]) {
                        id = i;
                        dif = s[i].top().second-e.t-f[e.id];
                    }
                }
                if(~id) {
                    s[id].push(make_pair(e.id, e.t+f[e.id]));
                    es.push(event(1,id,e.id,e.t+f[e.id]));
                }
                else {
                    rep(i,m) if(s[i].size() == 1) {
                        if(s[i].top().second < e.t+f[e.id] and dif > e.t+f[e.id]-s[i].top().second) {
                            id = i;
                            dif = e.t+f[e.id]-s[i].top().second;
                        }
                    }
                    if(~id) {
                        s[id].push(make_pair(e.id, e.t+f[e.id]));
                        es.push(event(1,id,e.id,e.t+f[e.id]));
                    }
                    else q.push(e.id);
                }
            }
        }
    }
    rep(i,n) cout << ans[i]+1 << (i==n-1? '\n': ' ');
}

bool input() {
    cin >> m >> n;
    rep(i,n) cin >> f[i];
    return n or m;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) solve();
    return 0;
}
