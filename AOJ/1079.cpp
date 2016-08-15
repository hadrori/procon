#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

int r[2], q, done[2][65536];
vector<tuple<int,int,int>> qs;

int solve()
{
    reverse(begin(qs),end(qs));
    memset(done,0,sizeof(done));
    int cnt[2] = {0,0}, ans = 0;
    for(auto &e: qs) {
        int a, b, o;
        tie(a,b,o) = e;
        if(done[a][b]) continue;
        done[a][b] = 1;
        cnt[a]++;
        if(o) ans += r[1-a]-cnt[1-a];
    }
    return ans;
}

bool input()
{
    cin >> r[0] >> r[1] >> q;
    int a, b, o;
    qs.clear();
    rep(i,q) {
        cin >> a >> b >> o;
        qs.push_back(make_tuple(a,b,o));
    }
    return r[0] or r[1] or q;
}

int main()
{
    while(input()) cout << solve() << endl;
    return 0;
}
