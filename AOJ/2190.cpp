#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

const int dx[] = {-1,1,2};
map<string,int> id;
int n, m, a[1<<16], b[1<<16];

int solve() {
    vector<int> pos, nxt;
    pos.push_back(-1);
    rep(i,m) {
        for(auto &p: pos) {
            if(p+(m-i)*2 < n-2) continue;
            rep(d,3) {
                const int np = p+dx[d];
                if(np >= 0 and np < n and (a[np]+(d==2)-(d==0)+12)%12 == b[i]) nxt.push_back(np);
            }
        }
        swap(pos,nxt);
        nxt.clear();
    }
    for(auto &p: pos) if(p > n-3) return 1;
    return 0;
}

void input() {
    cin >> n >> m;
    string s;
    rep(i,n) {
        cin >> s;
        a[i] = id[s];
    }
    rep(i,m) {
        cin >> s;
        b[i] = id[s];
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    id["C"] = 0; id["C#"] = 1; id["D"] = 2;
    id["D#"] = 3; id["E"] = 4; id["F"] = 5;
    id["F#"] = 6; id["G"] = 7; id["G#"] = 8;
    id["A"] = 9; id["A#"] = 10; id["B"] = 11;
    int t;
    cin >> t;
    while(t--) {
        input();
        cout << (solve()? "Yes": "No") << endl;
    }
    return 0;
}
