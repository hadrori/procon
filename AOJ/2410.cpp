#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

vector<int> hand;
int n, f[16], id[16];

bool cmp(int i, int j) { return __builtin_popcount(f[i]) > __builtin_popcount(f[j]); }

void build()
{
    rep(i,n) id[i] = i;
    sort(id,id+n,cmp);
    int g = 0;
    rep(i,n) if((g|f[id[i]]) != g) {
        hand.push_back(id[i]+1);
        g |= f[id[i]];
    }
}

void solve()
{
    build();
    srand(time(0));
    rep(_,1000) printf("%d\n", hand[rand()%hand.size()]);
}

void input()
{
    scanf("%d", &n);
    char s[16];
    rep(i,n) {
        scanf("%s", s);
        rep(j,n) if(s[j] == 'o') f[i] |= 1<<j;
    }
}

int main()
{
    input();
    solve();
    return 0;
}
