#include <iostream>
#include <string>
#include <map>

using namespace std;

#define rep(i,a) for(int (i) = 0; (i) < (a); (i)++)
#define repi(i,a,b) for(int (i) = (a); (i) < (b); (i)++)

typedef pair<int,int> pii;

int table[9][9];
bool pos[9][9][10];
int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};
pii last;
int ans, N;
bool inrange(int i, int j){ return i >= 0 && i < 9 && j >= 0 && j < 9;}

bool dfs(int i, int j){
    if(j == 9){
	i++;
	j = 0;
    }
    bool exist = false;
    rep(ni,9){
	rep(nj,9)if(!table[ni][nj]){
	    i = ni; j = nj;
	    exist = true;
	    break;
	}
	if(exist) break;
    }
    repi(n,1,10)if(!pos[i][j][n]){
	bool ok = true;
	rep(d,4){
	    int ni = i + di[d];
	    int nj = j + dj[d];
	    while(inrange(ni,nj)){
		if(table[ni][nj] == n){
		    ok = false;
		    break;
		}
		ni += di[d];
		nj += dj[d];
	    }
	    if(!ok) break;
	}
	if(!ok) continue;
	int si = i / 3, sj = j / 3;
	si *= 3; sj *= 3;
//	cerr << si << ' ' << sj << endl;
	repi(ni,si,si+3)repi(nj,sj,sj+3) if(table[ni][nj] == n){
	    ok = false;
	    break;
	}
	if(ok){
	    table[i][j] = n;
	    if(i == last.first && j == last.second){
		cerr << N << endl;
		rep(i,9)rep(j,9) cerr << table[i][j] << (j == 8? '\n': ' ');
		ans += table[0][0] * 100 + table[0][1] * 10 + table[0][2];
		return true;
	    }
	    bool fin = dfs(i,j+1);
	    if(fin) return true;
	    table[i][j] = 0;
	}
    }
    return false;
}


int main(){
    ans = 0;
    N = 1;
    while(N--){
        int __;
        string ___;
//        cin >> ___ >> __;
        memset(pos,0,sizeof(pos));
        string input;
        rep(i,9){
            cin >> input;
            rep(j,9) table[i][j] = input[j] - 48;
        }
        rep(i,9)rep(j,9)
            if(table[i][j]){
                rep(d,4){
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    while(inrange(ni,nj)){
                        if(!table[ni][nj]) pos[ni][nj][table[i][j]] = true;
                        ni += di[d];
                        nj += dj[d];
                    }
                }
                int si = i / 3, sj = j / 3;
                si *= 3; sj *= 3;
                repi(ni,si,si+3)repi(nj,sj,sj+3) if(!table[ni][nj])
                    pos[ni][nj][table[i][j]] = true;
            }else last = pii(i,j);
//	cerr << last.first << ' ' << last.second << endl;
        bool flag = false;
        dfs(0,0);
    }
    cout << ans << endl;
}
