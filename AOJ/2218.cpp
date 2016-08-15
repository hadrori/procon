#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

enum HAND {
    NONE,
    ONE_PAIR,
    TWO_PAIR,
    THREE_CARD,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_CARD,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH,
};

// A 2 3 4 5 6 7 8 9 T J Q K
// S C H D
// ex) (S,A) (S,2) (C,5) (D,Q) (H,J)
int poker_hand(const vector<pair<char,char>> &cards)
{
    assert((int)cards.size() == 5);
    int straight = 0, flush = 0, two = 0, three = 0, four = 0;
    map<char,int> cnt;
    set<char> ks;
    for (int i = 0; i < 5; i++) cnt[cards[i].second] += 1, ks.insert(cards[i].first);
    for(auto &e: cnt) {
        if(e.second == 2) two++;
        else if(e.second == 3) three++;
        else if(e.second == 4) four++;
    }
    if(two and three) return HAND::FULL_HOUSE;
    if(four) return HAND::FOUR_CARD;
    flush = (int)ks.size() == 1;
    vector<int> vs;
    for (int i = 0; i < 5; i++) vs.push_back(string("0A23456789TJQK").find(cards[i].second));
    sort(begin(vs),end(vs));
    const vector<int> royal = {1,10,11,12,13};
    if(vs == royal) straight = 1;
    else {
        straight = 1;
        for (int i = 0; i < 4; i++) if(vs[i+1]-vs[i] != 1) straight = 0;
    }
    if(straight and flush and vs == royal) return HAND::ROYAL_FLUSH;
    if(straight and flush) return HAND::STRAIGHT_FLUSH;
    if(four) return HAND::FOUR_CARD;
    if(straight) return HAND::STRAIGHT;
    if(flush) return HAND::FLUSH;
    if(three) return HAND::THREE_CARD;
    if(two == 2) return HAND::TWO_PAIR;
    if(two) return HAND::ONE_PAIR;
    return HAND::NONE;
}

const string s = "SCHD", t = "0A23456789TJQK";
int n, pt[4][16], ht[10];
vector<pair<char,char>> cs[10010];

void solve()
{
    rep(i,n) {
        int h = poker_hand(cs[i]), f = 0;
        rep(j,5) f += pt[s.find(cs[i][j].first)][t.find(cs[i][j].second)];
        cout << ht[h]*f << endl;
    }
}

void input()
{
    rep(i,n) cs[i].clear();
    rep(i,4) rep(j,13) cin >> pt[i][j+1];
    rep(i,9) cin >> ht[i+1];
    rep(i,n) {
        string s;
        rep(j,5) {
            cin >> s;
            cs[i].push_back(make_pair(s[1], s[0]));
        }
    }
}

int main()
{
    int t = 0;
    while(cin >> n) {
        if(t++) cout << endl;
        input();
        solve();
    }
    return 0;
}
