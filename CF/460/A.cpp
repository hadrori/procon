#include <bits/stdc++.h>
using namespace std;

int n, m;

int solve()
{
        for (int i = 0; i < 100000; i++)
                if(n-i+i/m < 1) return i;
        return 0;
}

void input()
{
        cin >> n >> m;
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
