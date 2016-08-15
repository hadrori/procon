#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;
typedef pair<int,int> pii;
int n, m;
queue<pii> q;

int solve(){
    
    while(!q.empty()){
        int b = q.front().first, i = q.front().second; q.pop();
        if(b-m>0) q.push(pii(b-m,i));
        if(q.empty()) return i;
    }
    return 0;
}

void input(){
    cin >> n >> m;
    int a;
    rep(i,n){
        cin >> a;
        q.push(pii(a,i+1));
    }
}

int main(){
    input();
    cout << solve() << endl;
    return 0;
}
