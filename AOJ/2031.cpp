#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const vector<string> hd = {"Rock", "Fire", "Scissors", "Snake", "Human", "Tree", "Wolf", "Sponge", "Paper", "Air", "Water", "Dragon", "Devil", "Lightning", "Gun"};

int n;
vector<int> vs;

inline bool win(int i, int j) {
    int x = ((j-i)+15)%15;
    return x < 8;
}

string solve() {
    vector<int> ws = vs;
    sort(begin(ws),end(ws));
    ws.erase(unique(begin(ws),end(ws)),end(ws));
    if((int)ws.size() == 1) return "Draw";
    rep(i,n) {
        bool ok = 1;
        rep(j,n) if(j != i) ok &= win(vs[i],vs[j]);
        if(ok) return hd[vs[i]];
    }
    return "Draw";
}

bool input() {
    cin >> n;
    string s;
    vs.clear();
    rep(i,n) {
        cin >> s;
        vs.push_back(find(begin(hd),end(hd),s)-begin(hd));
    }
    return n;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    for(int t = 0; input(); t++) {
        cout << solve() << endl;
    }
    return 0;
}
