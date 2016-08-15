#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;
typedef pair<int,int> pii;
int n, m, k, ans;
vector<pii> G[100010], H;
int d[100010];

struct node{
    int v, d, p;
    node(int v, int d, int p):v(v),d(d),p(p){}
    bool operator<(const node &n)const{
        if(d != n.d) return d > n.d;
        return p > n.p;
    }
};

void dijkstra(){
    memset(d, -1, sizeof(d));
    priority_queue<node> q;
    q.push(node(0,0,0));
    for(auto &p: H) q.push(node(p.first,p.second,1));
    while(!q.empty()){
        int v = q.top().v, ds = q.top().d, p = q.top().p;
        q.pop();
        if(d[v] >= 0) continue;
        if(p) --ans;
        d[v] = ds;
        for(auto &to: G[v])
            q.push(node(to.first,ds+to.second,0));
    }
}

int solve(){
    ans = k;
    dijkstra();
    return ans;
}

void input(){
    scanf("%d%d%d", &n, &m, &k);
    rep(i,m){
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        u--; v--;
        G[u].pb(pii(v,w)); G[v].pb(pii(u,w));
    }
    rep(i,k){
        int u, w; scanf("%d%d", &u, &w);
        u--;
        H.pb(pii(u,w));
    }
}

int main(){
    input();
    printf("%d\n", solve());
    return 0;
}
