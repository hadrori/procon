#include <bits/stdc++.h>
using namespace std;

int n, a[10010];

inline int append(int x, int y) { return atoi((to_string(x)+to_string(y)).c_str());}

int solve()
{
        sort(a,a+n);
        vector<int> s;
        for (int i = 0; i < min(4,n); i++)
                for (int j = 0; j < min(4,n); j++)
                        if(i != j) s.push_back(append(a[i], a[j]));

        sort(begin(s),end(s));
        return s[2];
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
                scanf("%d", a+i);
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
