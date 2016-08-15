#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

void solve()
{
        if(a == c) {
                int k = abs(d-b);
                cout << a + k << " " << b << " " << c+k << " " << d << endl;
        }
        else if(b == d) {
                int k = abs(a-c);
                cout << a << " " << b+k << " " << c << " " << d+k << endl;
        }
        else if(abs(a-c) != abs(b-d)){
                cout << -1 << endl;
        }
        else {
                cout << c << " " << b << " " << a << " " << d << endl;
        }
}

void input()
{
        cin >> a >> b >> c >> d;
}

int main()
{

        input();
        solve();
        return 0;
}
