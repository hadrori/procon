#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)

int n, a[100010], b[100010], pos;

int solve(){
    rep(i,n-1) if(a[i] > a[i+1]){
        pos = i+1;
        break;
    }
    if(pos == 0) return 0;
    memcpy(b,a+pos,sizeof(int)*(n-pos));
    memcpy(b+n-pos,a,sizeof(int)*pos);
    sort(a,a+n);
    rep(i,n) if(a[i] != b[i]) return -1;
    return (n-pos)%n;
}

void input(){
    scanf("%d", &n);
    rep(i,n) scanf("%d", a+i);
}

int main(){
    input();
    printf("%d\n", solve());
    return 0;
}
