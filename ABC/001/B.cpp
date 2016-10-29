#include "bits/stdc++.h"
using namespace std;

string f(string s) {
    if(int(s.size()) == 2) return s;
    return "0" + s;
}

string VV(int m) {
    if(m <    100) return "00";
    if(m <=  5000) return f(to_string(m/100));
    if(m <= 30000) return f(to_string(m/1000+50));
    if(m <= 70000) return f(to_string((m/1000-30)/5+80));
    return "89";
}

int main() {
    int m; scanf("%d", &m);
    printf("%s\n", VV(m).c_str());
    return 0;
}
