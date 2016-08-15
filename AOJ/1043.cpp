#include <bits/stdc++.h>
using namespace std;

int id[512], uv[512], ac[512], pn[512], rv[1024], n;

bool cmp(int a, int b)
{
        if(ac[rv[a]] != ac[rv[b]]) return ac[rv[a]] > ac[rv[b]];
        if(pn[rv[a]] != pn[rv[b]]) return pn[rv[a]] < pn[rv[b]];
        return a < b;
}

int cnt[1024], sc;

void solve()
{
        sort(id, id+n,cmp);
        memset(cnt,0,sizeof(cnt));
        sc = 0;
        for (int i = 0; i < n; i++) {
                if(sc < 10) {
                        if(cnt[uv[rv[id[i]]]] < 3) {
                                sc++;
                                cnt[uv[rv[id[i]]]]++;
                                cout << id[i] << endl;
                        }
                }
                else if(sc < 20) {
                        if(cnt[uv[rv[id[i]]]] < 2) {
                                sc++;
                                cnt[uv[rv[id[i]]]]++;
                                cout << id[i] << endl;
                        }
                }
                else if(sc < 26) {
                        if(cnt[uv[rv[id[i]]]] < 1) {
                                sc++;
                                cnt[uv[rv[id[i]]]]++;
                                cout << id[i] << endl;
                        }                        
                }
        }
}

bool input()
{
        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> id[i] >> uv[i] >> ac[i] >> pn[i];
                rv[id[i]] = i;
        }
        return n;
}

int main()
{
        while(input()) solve();
        return 0;
}
