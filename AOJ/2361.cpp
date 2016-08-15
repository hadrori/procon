#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int vtoi(vi &v){
    int ret = 0;
    rep(i,v.size()){
        ret *= 10;
        ret += v[i];
    }
    return ret;
}

void itov(int n, vi &v){
    int t = v.size();
    rep(i,t){
        v[t-i-1] = n%10;
        n/=10;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vi> cost(n,vi(n));
    rep(i,n)rep(j,n) cin >> cost[i][j];
    vi v(n);
    rep(i,n) v[i] = i;
    int num = vtoi(v);
    priority_queue<pii> que;
    map<int,int> d;
    que.push(pii(num,0));
    d[num] = 0;
    while(!que.empty()){
        num = que.top().first;
        int dist = -que.top().second;
        que.pop();
        if(dist > d[num]) continue;
        vi tmp(n);
        rep(i,n)repi(j,i+1,n){
            itov(num,tmp);
            swap(tmp[i],tmp[j]);
            int t = vtoi(tmp);
            int cst = cost[tmp[i]][tmp[j]];
            map<int,int>::iterator itr = d.find(t);
            if(itr == d.end() || (*itr).second > dist + cst){
                d[t] = dist + cst;
                que.push(pii(t,-dist-cst));
            }
        }
    }
    int ans = 0;
    repit(itr,d) ans = max(ans,(*itr).second);
    cout << ans << endl;
    return 0;
}
