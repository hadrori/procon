#include <bits/stdc++.h>
using namespace std;

int p[128];
string o, s[2];

string solve(int l[], int r[])
{
        if(o == "i" and (r[0]-l[0] <= 0 or r[1]-l[1] <= 0)) return "";
        if(r[0]-l[0] <= 0 and r[1]-l[1] <= 0) return "";
        int lm[] = {l[0], l[1]}, rm[] = {l[0], l[1]};
        for (int i = 0; i < 2; i++) {
                if(r[i]-l[i] <= 0) continue;
                l[i]++; r[i]--;
                int d = 0;
                do {
                        lm[i]++;
                        if(s[i][lm[i]] == '(') d++;
                        else if(s[i][lm[i]] == ')') d--;
                } while(d > 0 or s[i][lm[i]] != ',');
                rm[i] = lm[i]+1;
        }

        return "("+solve(l,lm)+","+solve(rm,r)+")";
}

int main()
{
        int l[2], r[2];
        while(cin >> o >> s[0] >> s[1]) {
                for (int i = 0; i < 2; i++) {
                        l[i] = 0;
                        r[i] = s[i].size();
                }
                cout << solve(l,r) << endl;
        }
        return 0;
}
