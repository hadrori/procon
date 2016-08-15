#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> s;
int n;

void solve()
{
        sort(begin(s),end(s));
        cout << s[0].second << " " << -s[0].first << endl;
}

void input()
{
        cin >> n;
        int a, b;
        for (int i = 0; i < n; i++) {
                cin >> a >> b;
                s.emplace_back(-b,a);
        }
}

int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        input();
        solve();
        return 0;
}
