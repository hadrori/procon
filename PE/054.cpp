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
#include <fstream>

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

enum rank{
    HighCard,
    OnePair,
    TwoPair,
    ThreeCards,
    Straight,
    Flush,
    FullHouse,
    FourCards,
    StraightFlush,
    RoyalFlush,
};

struct Card{
    int num;
    char suit;
    Card(int num, char suit):num(num),suit(suit){}
    bool operator<(const Card &c)const{
	return num < c.num;
    }
};

bool is1Win(vector<Card> p[]){
    vector<pii> ranks[2];
    rep(i,2){
	bool straight = true;
	rep(j,5)if(p[i][0].num + j != p[i][j].num)straight = false;
	if(straight){
	    if(p[i][0].num == 10){
		if(p[i][0].suit == p[i][1].suit && p[i][0].suit == p[i][2].suit &&
		   p[i][0].suit == p[i][3].suit && p[i][0].suit == p[i][4].suit){
		    ranks[i].pb(mp(RoyalFlush,14));
		}
		else ranks[i].pb(mp(Straight,14));
	    }else{
		if(p[i][0].suit == p[i][1].suit && p[i][0].suit == p[i][2].suit &&
		   p[i][0].suit == p[i][3].suit && p[i][0].suit == p[i][4].suit){
		    ranks[i].pb(mp(StraightFlush,p[i][4].num));
		}
		else ranks[i].pb(mp(Straight,p[i][4].num));
	    }
	    continue;
	}
	int cnt[15] = {0};
	rep(j,5)cnt[p[i][j].num]++;
	int combi[4] = {0};
	rep(j,15)combi[cnt[j]]++;
	if(combi[4]){
	    ranks[i].pb(mp(FourCards,p[i][3].num));
	    rep(j,15)if(cnt[j] == 1) ranks[i].pb(mp(HighCard,j));
	    continue;
	}
	if(combi[2] && combi[3]){
	    ranks[i].pb(mp(FullHouse,100*p[i][4].num+p[i][0].num));
	    continue;
	}
	if(p[i][0].suit == p[i][1].suit && p[i][0].suit == p[i][2].suit &&
	   p[i][0].suit == p[i][3].suit && p[i][0].suit == p[i][4].suit){
	    ranks[i].pb(mp(Flush,p[i][4].num));
	    continue;
	}
	if(combi[3]){
	    int s = 0, t;
	    repd(j,14,2){
		if(cnt[j] == 3) t = j;
		else if(cnt[j] == 1){
		    s *= 100;
		    s += j;
		}
	    }
	    ranks[i].pb(mp(ThreeCards,t));
	    ranks[i].pb(mp(HighCard,s));
	    continue;
	}
	if(combi[2] == 2){
	    int s, t = 0;
	    repd(j,14,2){
		if(cnt[j] == 2){
		    t *= 100;
		    t += j;
		}else if(cnt[j] == 1) s = j;
	    }
	    ranks[i].pb(mp(TwoPair,t));
	    ranks[i].pb(mp(HighCard,s));
	    continue;
	}
	if(combi[2] == 1){
	    int s = 0, t;
	    repd(j,14,2){
		if(cnt[j] == 2) t = j;
		else if(cnt[j] == 1){
		    s *= 100;
		    s += j;
		}
	    }
	    ranks[i].pb(mp(OnePair,t));
	    ranks[i].pb(mp(HighCard,s));
	    continue;
	}
	int t = 0;
	repd(j,4,0){
	    t *= 100;
	    t += p[i][j].num;
	}
	ranks[i].pb(mp(HighCard,t));
    }
    if(ranks[0][0].first > ranks[1][0].first) return true;
    if(ranks[0][0].first < ranks[1][0].first) return false;
    if(ranks[0][0].second > ranks[1][0].second) return true;
    if(ranks[0][0].second < ranks[1][0].second) return false;
    if(ranks[0][1].first > ranks[1][1].first) return true;
    if(ranks[0][1].first < ranks[1][1].first) return false;
    if(ranks[0][1].second > ranks[1][1].second) return true;
    if(ranks[0][1].second < ranks[1][1].second) return false;
}

int main(){
    ifstream ifs("poker.txt");
    int ans = 0;
    rep(i,1000){
	vector<Card> p[2];
	rep(k,2){
	    rep(j,5){
		char a, b;
		int c;
		ifs >> a >> b;
		if(a == 'T') c = 10;
		else if(a == 'J') c = 11;
		else if(a == 'Q') c = 12;
		else if(a == 'K') c = 13;
		else if(a == 'A') c = 14;
		else c = a - '0';
		p[k].pb(Card(c,b));
	    }
	}
	sort(all(p[0])); sort(all(p[1]));
	if(is1Win(p))ans++;
    }
    cout << ans << endl;
    return 0;
}
