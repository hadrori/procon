#include <bits/stdc++.h>
using namespace std;

int reduct(int l, int r, const vector<pair<int,int>> &s)
{
        if(l < 0 or r >= (int)s.size()) return 0;
        if(s[r].second == 0) return reduct(l,r+1,s);
        if(s[l].second == 0) return reduct(l-1,r,s);
        int sum = s[l].second;
        if(l != r) sum += s[r].second;
        if(s[l].first != s[r].first or sum < 4) return 0;
        return sum+reduct(l-1, r+1, s);
}

int n;

int solve()
{
        vector<pair<int,int>> s;
        for (int i = 0; i < n; i++) {
                int c; scanf("%d", &c);
                if(s.empty() or s.back().first != c) s.push_back(pair<int,int>(c,1));
                else s.back().second++;
                if(s.back().second > 3) s.pop_back();
        }

        int ans = n;
        for (int i = 0; i < (int)s.size(); i++) {
                if(i > 0 and i < (int)s.size()-1 and s[i].second == 1 and s[i-1].first == s[i+1].first) {
                        s[i-1].second++;
                        ans = min(ans, n-reduct(i-1,i+1, s));
                        s[i-1].second--;
                }
                else {
                        if(i > 0) {
                                s[i-1].second++;
                                s[i].second--;
                                ans = min(ans, n-reduct(i-1,i-1, s));
                                s[i-1].second--;
                                s[i].second++;
                        }
                        if(i < (int)s.size()-1) {
                                s[i+1].second++;
                                s[i].second--;
                                ans = min(ans, n-reduct(i+1,i+1, s));
                                s[i+1].second--;
                                s[i].second++;
                        }
                }
        }

        return ans;
}

int main()
{
        while(scanf("%d", &n), n) printf("%d\n", solve());
        return 0;
}
