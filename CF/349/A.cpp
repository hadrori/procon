#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int main(){
    int n;
    cin >> n;
    int c;
    int cnt[101] = {0};
    cnt[0] = INF;
    rep(i,n) {
        cin >> c;
        int d = c - 25;
        if(d == 0){
            cnt[c]++;
        }
        else if(d == 25 && cnt[d] > 0){
            cnt[d]--;
            cnt[c]++;
        }
        else if(d == 50 && cnt[d] > 0){
            cnt[d]--;
            cnt[c]++;
        }
        else if(d == 50 && cnt[25] > 1){
            cnt[25] -= 2;
            cnt[c]++;
        }
        else if(d == 75 && cnt[50] > 0 && cnt[25] > 0){
            cnt[50]--;
            cnt[25]--;
            cnt[c]++;
        }
        else if(d == 75 && cnt[25] > 2){
            cnt[25] -= 3;
            cnt[c]++;
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    
    return 0;
}
