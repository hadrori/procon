#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, c;

int sum(int x)
{
        if(x < 0 or x >= (int)1e9) return -1;
        int ret = 0;
        while(x) {
                ret += x%10;
                x /= 10;
        }
        return ret;
}

void solve()
{
        vector<int> ans;

        for (int s = 1; s < 82; s++) {
                int sa = 1;
                for (int i = 0; i < a; i++) sa *= s;
                int x = b*sa+c;
                if(sum(x) == s) ans.push_back(x);
        }
        sort(begin(ans),end(ans));
        cout << ans.size() << endl;
        for(auto &e: ans) cout << e << " ";
        if(ans.size()) cout << endl;
}

void input()
{
        cin >> a >> b >> c;
}

signed main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
