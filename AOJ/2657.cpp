#include <bits/stdc++.h>
using namespace std;

int n, m, date[128];
string title[128], author[128];

int calc(string u) { return atoi(u.substr(0,4).c_str())*10000+atoi(u.substr(5,2).c_str())*100+atoi(u.substr(8,2).c_str()); }

void solve()
{
    string a, b, c, d;
    while(m--) {
        cin >> a >> b >> c >> d;
        for (int i = 0; i < n; i++) {
            if(a != "*" and title[i].find(a) == string::npos) continue;
            if(b != "*" and author[i].find(b) == string::npos) continue;
            if(c != "*" and calc(c) > date[i]) continue;
            if(d != "*" and calc(d) < date[i]) continue;
            cout << title[i] << endl;
        }
        if(m) cout << endl;
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s, t, u;
        cin >> s >> t >> u;
        title[i] = s;
        author[i] = t;
        date[i] = calc(u);
    }
    cin >> m;
}

int main()
{
    input();
    solve();
    return 0;
}
