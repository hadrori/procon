#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,n) repi(i,0,n)

set<int> operator-(const set<int> &x, const set<int> &y) {
    set<int> ret;
    set_difference(begin(x), end(x), begin(y), end(y), inserter(ret, begin(ret)));
    return ret;
}

set<int> operator&(const set<int> &x, const set<int> &y) {
    set<int> ret;    
    set_intersection(begin(x), end(x), begin(y), end(y), inserter(ret, begin(ret)));
    return ret;
}

set<int> operator|(const set<int> &x, const set<int> &y) {
    set<int> ret;
    set_union(begin(x), end(x), begin(y), end(y), inserter(ret, begin(ret)));
    return ret;
}

int id[256];
set<int> S[8], U;

int n;
string s;

int get_r(int l) {
    int d = 0;
    do {
        if(s[l] == '(') d++;
        if(s[l] == ')') d--;
        l++;
    } while(d or islower(s[l-1]));
    return l;
}

set<int> expr(int l, int r);

set<int> val(int i) {
    if(s[i] != '(' and s[i] != 'c') return S[id[(int)s[i]]];
    if(s[i] == '(') return expr(i+1, get_r(i)-1);
    return expr(i,get_r(i));
}

set<int> eval(char op, const set<int> &x, const set<int> &y) {
    set<int> ret;
    if(op == 'i') ret = x&y;
    else if(op == 'u') ret = x|y;
    else if(op == 'd') ret = x-y;
    else if(op == 's') ret = (x-y)|(y-x);
    return ret;
}

set<int> expr(int l, int r) {
    if(l >= r) return set<int>();
    set<int> x;
    int nr, c = 0;
    if(s[l] == 'c') {
        c = 1;
        l++;
    }
    nr = get_r(l);
    x = val(l);
    if(c) x = U-x;

    l = nr;
    while(l < r) {
        nr = get_r(l+1);
        x = eval(s[l],x,expr(l+1,nr));
        l = nr;
    }
    return x;
}

void solve() {
    n = s.size();
    set<int> ans = expr(0,n);
    n = ans.size();
    if(!n) {
        puts("NULL");
        return;
    }
    int i = 0;
    for(auto &e: ans) {
        cout << e;
        if(i == n-1) cout << endl;
        else cout << ' ';
        i++;
    }
}

bool input() {
    U.clear();
    char a;
    int b, x, idx = 0;
    if(!(cin >> a)) return 0;
    cin >> b;

    do {
        id[(int)a] = idx++;
        set<int> vs;
        rep(i,b) {
            cin >> x;
            vs.insert(x);
            U.insert(x);
        }
        S[id[(int)a]] = set<int>(vs);
        cin >> a >> b;
    } while(a != 'R');
    cin >> s;
    return 1;
}

int main() {
    while(input()) solve();
    return 0;
}
