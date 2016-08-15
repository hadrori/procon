#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

inline void add(int &x, int y) { x = (x+y)%mod;}
int na, nt, ng, nc, m, dp[51][51][51][51], cur, idx;
map<string, int> id;
vector<int> seq[51], vs;

void calc(const int &v)
{
        for (int w =0; w <= min(cur, na); w++) {
                for (int x = 0; x <= min(cur-w, nt); x++) {
                        for (int y = 0; y <= min(cur-w-x, ng); y++) {
                                const int z = cur-w-x-y;
                                if(v&1 and w < na) add(dp[w+1][x][y][z], dp[w][x][y][z]);
                                if(v&2 and x < nt) add(dp[w][x+1][y][z], dp[w][x][y][z]);
                                if(v&4 and y < ng) add(dp[w][x][y+1][z], dp[w][x][y][z]);
                                if(v&8 and z < nc) add(dp[w][x][y][z+1], dp[w][x][y][z]);
                        }
                }
        }
        cur++;
}

int dfs(int v)
{
        if(v < 0) {
                if((int)vs.size() >= na+nt+ng+nc or cur < 0) return 0;
                vs.push_back(-v);
                return 1;
        }
        for(auto &e: seq[v]) if(!dfs(e)) return 0;
        return 1;
}

void debug()
{
        for (int i = 0; i < m; i++) {
                for(auto &e: seq[i]) cerr << e << ' ';
                cerr << endl;
        }
}       

int solve()
{
        // debug();
        dp[0][0][0][0] = 1;
        if(!dfs(0) or na+nt+ng+nc != (int)vs.size()) return 0;
        for(auto &v: vs) calc(v);
        return dp[na][nt][ng][nc];
}

int encode(const string &t)
{
        int ret = 0;
        if(t[0] == '[') {
                const string s = "ATGC";
                for (int i = 1; i < (int)t.size()-1; i++) ret -= 1<<s.find(t[i]);
        }
        else {
                if(!id.count(t)) id[t] = idx++;
                ret = id[t];
        }
        return ret;
}

void input()
{
        cin >> na >> nt >> ng >> nc >> m;
        cin.ignore();
        for (int i = 0; i < m; i++) {
                string t; getline(cin, t);
                stringstream ss(t);
                ss >> t;
                t = t.substr(0,t.size()-1);
                int v = encode(t);
                while(ss >> t) seq[v].push_back(encode(t));
        }
}

int main()
{
        input();
        cout << solve() << endl;
        return 0;
}
