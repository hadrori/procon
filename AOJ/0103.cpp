#include <bits/stdc++.h>
using namespace std;

int solve()
{
        int o = 0, run = 0, p = 0;
        string s;
        while(o < 3) {
                cin >> s;
                if(s == "OUT") o++;
                else if(s == "HIT") {
                        if(run == 3) p++;
                        else run++;
                }
                else if(s == "HOMERUN") {
                        p += run+1;
                        run = 0;
                }
        }
        return p;
}

int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        int t; cin >> t;
        while(t--) cout << solve() << endl;
        return 0;
}
