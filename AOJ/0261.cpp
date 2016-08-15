#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

const int month_day[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

string s;

inline bool is_leap(int y) { return y%4 == 0 and (y%100 != 0 or y%400 == 0);}
inline int leap_count(int y) { return (y-1)/4-(y-1)/100+(y-1)/400; }
inline i64 day_count(int y, int m, int d) { return leap_count(y)*366LL+(y-leap_count(y))*365LL+month_day[m-1]+(is_leap(y)&(m>2))+d; }

void to_maya()
{
        int y, m, d;
        sscanf(s.c_str(),"%d.%d.%d", &y, &m, &d);
        i64 ds = (day_count(y,m,d)-day_count(2012,12,21))%(20*18*20*20*13);
        printf("%lld.%lld.%lld.%lld.%lld\n", ds/(20*18*20*20), ds/(20*18*20)%20, ds/(20*18)%20, ds/20%18, ds%20);
}

void to_ad()
{
        int b, ka, t, w, ki;
        sscanf(s.c_str(),"%d.%d.%d.%d.%d", &b, &ka, &t, &w, &ki);
        i64 ds = ki+20*w+20*18*t+20*18*20*ka+20*18*20*20*b+day_count(2012,12,21);
        int y = 0, m = 0, d = 0;
        while(ds >= is_leap(y)+365) ds -= is_leap(y++)+365;
        while(ds >= month_day[m+1]+(is_leap(y)&(m>=1))) m++;
        ds -= month_day[m]+(is_leap(y)&(m>1));
        m++;
        d = ds+1;
        printf("%d.%d.%d\n", y, m, d);
}

void solve()
{
        int cnt = 0;
        for(auto &e: s) cnt += e == '.';
        return cnt == 2 ? to_maya() : to_ad();
}

bool input()
{
        cin >> s;
        return s[0] != '#';
}

int main()
{
        while(input()) solve();
        return 0;
}

