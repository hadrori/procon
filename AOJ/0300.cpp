#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

vector<int> f;

bool valid() {
    int ok = 1;
    rep(i,29) if(i != 8 and i != 11 and i != 14 and i != 17 and i != 20) ok &= f[i] == f[i+1];
    return ok;
}

vector<int> roll1() {
    vector<int> t = f;
    t[0] = f[27];
    t[1] = f[28];
    t[2] = f[29];
    t[14] = f[15];
    t[15] = f[14];
    t[27] = f[0];
    t[28] = f[1];
    t[29] = f[2];
    t[18] = f[20];
    t[20] = f[18];
    return t;
}

vector<int> roll2() {
    vector<int> t = f;
    t[6] = f[21];
    t[7] = f[22];
    t[8] = f[23];
    t[12] = f[17];
    t[17] = f[12];
    t[21] = f[6];
    t[22] = f[7];
    t[23] = f[8];
    t[9] = f[11];
    t[11] = f[9];
    return t;
}

vector<int> roll3() {
    vector<int> t = f;
    t[2] = f[21];
    t[5] = f[24];
    t[8] = f[27];
    t[11] = f[18];
    t[18] = f[11];
    t[21] = f[2];
    t[24] = f[5];
    t[27] = f[8];
    t[12] = f[14];
    t[14] = f[12];
    return t;
}

vector<int> roll4() {
    vector<int> t = f;
    t[0] = f[23];
    t[3] = f[26];
    t[6] = f[29];
    t[9] = f[20];
    t[20] = f[9];
    t[23] = f[0];
    t[26] = f[3];
    t[29] = f[6];
    t[15] = f[17];
    t[17] = f[15];
    return t;
}

int solve() {
    queue<pair<int,vector<int>>> q;
    q.push(make_pair(0,f));
    while(!q.empty()) {
        f = q.front().second;
        int d = q.front().first;
        q.pop();
        if(valid()) return d;
        q.push(make_pair(d+1,roll1()));
        q.push(make_pair(d+1,roll2()));
        q.push(make_pair(d+1,roll3()));
        q.push(make_pair(d+1,roll4()));
    }
    return -1;
}

void input() {
    rep(i,30) cin >> f[i];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    f.resize(30);
    while(t--) {
        input();
        cout << solve() << endl;
    }
    return 0;
}
