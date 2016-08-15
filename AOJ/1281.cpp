#include <bits/stdc++.h>
using namespace std;
const char abc[] = "ABC";
const int di[] = {0,1,0,-1,0}, dj[] = {1,0,-1,0,0};

char f[16][16];
int st, w, h, n, m, cd, goal;
short ps[4][2], qs[4][2], dist[1<<24];
queue<int> q;

bool next(int i)
{
        if(i == m) {
                st = 0;
                for (int j = 0; j < m; j++) st += (qs[j][0]*16+qs[j][1])<<(j*8);
                if(~dist[st]) return 0;
                dist[st] = cd+1;
                if(st == goal) return 1;
                q.push(st);
                return 0;
        }
        for (int d = 0; d < 5; d++) {
                qs[i][0] = ps[i][0]+di[d];
                qs[i][1] = ps[i][1]+dj[d];
                if(f[qs[i][0]][qs[i][1]] == '#') continue;
                bool valid = 1;
                for (int j = 0; j < i; j++)
                        if((qs[i][0] == qs[j][0] and qs[i][1] == qs[j][1]) or
                           (qs[i][0] == ps[j][0] and qs[i][1] == ps[j][1] and qs[j][0] == ps[i][0] and qs[j][1] == ps[i][1])) {
                                valid = 0;
                                break;
                        }
                if(valid and next(i+1)) return 1;
        }
        return 0;
}

int solve()
{
        while(!q.empty()) q.pop();
        for (int i = 0; i < 1<<24; i++) dist[i] = -1;
        dist[st] = 0;
        q.push(st);

        while(1) {
                st = q.front(); q.pop();
                cd = dist[st];
                for (int i = 0; i < m; i++) {
                        ps[i][0] = st/16%16;
                        ps[i][1] = st%16;
                        st /= 256;
                }
                if(next(0)) return dist[goal];
        }
        return -1;
}

bool input()
{
        cin >> w >> h >> n;
        cin.ignore();
        m = st = goal = 0;
        for (int i = 0; i < h; i++) {
                string s;
                getline(cin, s);
                
                for (int j = 0; j < w; j++) {
                        f[i][j] = s[j];
                        if(f[i][j] == 'a') {
                                st += i*16+j;
                                m++;
                        }
                        else if(f[i][j] == 'b') {
                                st += (i*16+j)<<8;
                                m++;
                        }
                        else if(f[i][j] == 'c') {
                                st |= (i*16+j)<<16;
                                m++;
                        }
                        else if(f[i][j] == 'A') goal += i*16+j;
                        else if(f[i][j] == 'B') goal += (i*16+j)<<8;
                        else if(f[i][j] == 'C') goal += (i*16+j)<<16;
                }
        }
        return w or h or n;
}

int main()
{
        while(input()) cout << solve() << endl;
        return 0;
}
