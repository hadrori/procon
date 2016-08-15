#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)

int t, a, b;

void solve() {
    if(t < max(a,b)) {
        puts("NO");
        return;
    }
    int i = 0, j = 0;
    if((t-max(a,b))%2) {
        if(a and b) {
            puts("YES");
            i++; j++;
            t -= 2;
            puts("^");
            puts(">");
        }
        else if(a or b){
            puts("YES");
            i++; j++;
            t--;
            puts("^>");
        }
        else {
            if(t == 1) {
                puts("NO");
                return;
            }
            else {
                puts("YES");
                i++; j++;
                t--;
                puts("^>");
            }
        }
    }
    else puts("YES");

    while(i < a and j < b) {
        t--;
        puts("^>");
        i++; j++;
    }
    while(i < a) {
        t--;
        puts("^");
        i++;
    }
    while(j < b) {
        t--;
        puts(">");
        j++;
    }
    if(j > b) {
        t--;
        puts("<");
    }
    if(i > a) {
        t--;
        puts("v");
    }
    while(t > 0) {
        t -= 2;
        puts(">");
        puts("<");
    }
}

void input() {
    scanf("%d%d%d", &t, &a, &b);
}

int main() {
    input();
    solve();
    return 0;
}
