#include <bits/stdc++.h>
using namespace std;

const int H = 50, W = 100, D = 30;

struct event
{
        double t;
        int pos, idx;
        event(){}
        event(double t, int pos, int idx) : t(t), pos(pos), idx(idx) {}
        bool operator<(const event &e) const { return t > e.t; }
};

int n, l;
vector<int> b, h, f, p, t;
vector<double> q, ans;

void merge(int i)
{
        q[i] += q[i+1];
        f[i] += f[i+1];
        b.erase(begin(b)+i+1,begin(b)+i+2);
        q.erase(begin(q)+i+1,begin(q)+i+2);
        f.erase(begin(f)+i+1,begin(f)+i+2);
        h.erase(begin(h)+i+1,begin(h)+i+2);
}

void debug(event e)
{
        int m = h.size()-1;
        cerr << fixed << setprecision(3);
        cerr << e.t << ' ' << e.pos << endl;
        if(~e.idx) cerr << "show query" << endl;
        cerr << "b" << '\t';
        for (int i = 0; i <= m; i++) cerr << b[i] << '\t'; cerr << endl;
        cerr << "h" << '\t';
        for (int i = 0; i <= m; i++) cerr << h[i] << '\t'; cerr << endl;
        cerr << "f" << '\t';
        for (int i = 0; i < m; i++) cerr << f[i] << '\t'; cerr << endl;
        cerr << "q" << '\t';
        for (int i = 0; i < m; i++) cerr << q[i]/(b[i+1]-b[i])/D << '\t'; cerr << endl;
}

void solve()
{
        ans.assign(l,0);
        priority_queue<event> pq;
        for (int i = 0; i < l; i++) pq.push(event(t[i],p[i],i));
        for (int i = 0; i < n; i++) if(f[i]) pq.push(event(1.*min(h[i],h[i+1])*(b[i+1]-b[i])*D/f[i], b[i], -1));
        double pt = 0;
        int over = 0;
        while(!pq.empty()) {
                n = b.size()-1;
                event e = pq.top(); pq.pop();
                if(over) {
                        if(~e.idx) ans[e.idx] = 50;
                        continue;
                }
                int idx = upper_bound(begin(b),end(b),e.pos)-begin(b)-1;
                // cerr << e.pos << ' ' << idx << endl;
                double dt = e.t-pt;
                for (int i = 0; i < n; i++) q[i] += dt*f[i];
                if(!~e.idx) {
                        double ch = min(h[idx],h[idx+1]);
//                        if(q[idx]+dt*f[idx] < ch*(b[idx+1]-b[idx])*D) q[idx] += dt*f[idx];
                        if(abs(q[idx]-ch*(b[idx+1]-b[idx])*D) < 1e-6) {
                                if(h[idx] < h[idx+1]) {
                                        double lh = q[idx-1]/(b[idx]-b[idx-1])/D;
                                        if(abs(ch-lh) < 1e-6) merge(idx-1);
                                        else {
                                                f[idx-1] += f[idx];
                                                f[idx] = 0;
                                        }
                                        if(f[idx-1]) pq.push(event(e.t+(min(h[idx-1],h[idx])-lh)*(b[idx]-b[idx-1])*D/f[idx-1],b[idx-1],-1));
                                }
                                else if(h[idx] > h[idx+1]){
                                        double rh = q[idx+1]/(b[idx+2]-b[idx+1])/D;
                                        if(abs(ch-rh) < 1e-6) {
                                                merge(idx);
                                                if(f[idx]) pq.push(event(e.t+(min(h[idx+1],h[idx])-rh)*(b[idx+1]-b[idx])*D/f[idx],b[idx],-1));
                                        }
                                        else {
                                                f[idx+1] += f[idx];
                                                f[idx] = 0;
                                                if(f[idx+1]) pq.push(event(e.t+(min(h[idx+2],h[idx+1])-rh)*(b[idx+2]-b[idx+1])*D/f[idx+1],b[idx+1],-1));
                                        }
                                }
                                else over = 1;
                        }
                }
                else ans[e.idx] = q[idx]/(b[idx+1]-b[idx])/D;
                // debug(e);
                pt = e.t;
        }
        for (int i = 0; i < l; i++) printf("%.10f\n", ans[i]);
}

void init()
{
        b = {0};
        h = {H};
        q.assign(n+1,0);
        f.assign(n+1,0);
}

void input()
{
        scanf("%d", &n);
        init();
        for (int i = 0; i < n; i++) {
                int x, y; scanf("%d%d", &x, &y);
                b.push_back(x);
                h.push_back(y);
        }
        b.push_back(W);
        h.push_back(H);
        n++;
        int m; scanf("%d", &m);
        for (int i = 0; i < m; i++) {
                int x, y; scanf("%d%d", &x, &y);
                f[upper_bound(begin(b),end(b),x)-begin(b)-1] += y;
        }
        scanf("%d", &l);
        p.clear(); t.clear();
        for (int i = 0; i < l; i++) {
                int x, y; scanf("%d%d", &x, &y);
                p.push_back(x);
                t.push_back(y);
        }
}

int main()
{
        int t; scanf("%d", &t);
        while(t--) {
                input();
                solve();
        }
        return 0;
}
