#include "bits/stdc++.h"
using namespace std;

#define reps(i,a,b,s) for(int i=(int)(a);i<(int)(b);i+=s)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
using i64 = int64_t;
double rate[40][1024][4]; // [pos][CH][CC]
const int mch[] = {0,10,11,24,39,5,-1,-1,-2,-3,-4,-4,-4,-4,-4,-4};
const int mcc[] = {0,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int exec_cc(int p, int cc) {
    if(mcc[cc] < 0) return p;
    return mcc[cc];
}

int exec_ch(int p, int ch) {
    switch(mch[ch]) {
    case -4: return p;
    case -3: return (p+37)%40;
    case -2:
        if(12 < p and p < 28) return 28;
        else return 12;
    case -1:
        if(5 <= p and p < 15) return 15;
        else if(15 <= p and p < 25) return 25;
        else if(25 <= p and p < 35) return 35;
        return 5;
    default: return mch[ch];
    }
}

int next(int p, vector<int> &cc, vector<int> &ch) {
    int c = 0, a, b;
    do {
        if(c++ == 3) return 10;
        a = rand()%4+1; b = rand()%4+1;
        p += a + b;
    } while(a == b);
    p %= 40;
    if(p == 30) return 10;
    if(p == 2 or p == 17 or p == 33) {
        int c = cc[0];
        cc = vector<int>(begin(cc)+1, end(cc));
        cc.push_back(c);
        return exec_cc(p, c);
    }
    if(p == 7 or p == 12 or p == 36) {
        int c = ch[0];
        ch = vector<int>(begin(ch)+1, end(ch));
        ch.push_back(c);
        return exec_ch(p, ch[0]);
    }
    return p;
}

void solve() {
    vector<int> cnt(40);
    srand(time(0));
    rep(_,100000) {
        vector<int> cc = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        vector<int> ch = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        random_shuffle(begin(cc),end(cc));
        random_shuffle(begin(ch),end(ch));
        int p = 0;
        rep(__,1000) cnt[p = next(p,cc,ch)]++;
    }
    vector<pair<int,int>> vs;
    rep(i,40) vs.emplace_back(cnt[i], i);
    sort(begin(vs),end(vs));
    reverse(begin(vs),end(vs));
    rep(i,40) cout << vs[i].second << ' '; cerr << endl;
}

int main() {
    solve();
    return 0;
}
