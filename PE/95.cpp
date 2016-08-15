#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;

const int N = 1e6;

int to[N+1], chain[N+1], dist[N+1];

void dump(int x) {
    int f[N+1];
    memset(f,0,sizeof(f));
    while(!f[x]) {
        cerr << x << " -> ";
        f[x] = 1;
        x = to[x];
    }
    cerr << "( " << x << " -> ...)" << endl;
}

void solve() {
    rep(x,N) {
        int sum = -x;
        for(int i = 1; i*i <= x; i++)
            if(x%i == 0) sum += i + (i*i != x) * x/i;
        to[x] = sum;
    }
    int c = 0, len = 1, ans = N;
    rep(i,N) if(!chain[i]) {
        int x = i; c++;
        while(!chain[x]) {
            chain[x] = c;
            if(to[x] > N) break;
            if(chain[to[x]] == c) {
                int l = dist[x] - dist[to[x]] + 1, m = x;
                int s = to[x];
                while(s != x) m = min(m, s), s = to[s];
                if(l > len) {
                    ans = m;
                    len = l;
                }
                else if(l == len) ans = min(ans, m);
            }
            dist[to[x]] = dist[x]+1;
            x = to[x];
        }
    }
    dump(12496);
    dump(5916);
    cout << "length : " << len << endl;
    cout << "answer : " << ans << endl;
}

int main() {
    solve();
    return 0;
}
