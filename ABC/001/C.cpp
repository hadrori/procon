#include "bits/stdc++.h"
using namespace std;

const string dirs[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
const int bnds[] = {112, 337, 562, 787, 1012, 1237, 1462, 1687, 1912, 2137, 2362, 2587, 2812, 3037, 3262, 3487, 3600};
const int nums[] = {14, 92, 200, 326, 476, 644, 830, 1028, 1244, 1466, 1706, 1958, 12000};

int f(int Dis) { return lower_bound(nums, nums+13, Dis) - nums; }
string g(int W, int Deg) { return W ? dirs[lower_bound(bnds,  bnds+17, Deg) - bnds] : "C"; }

int main() {
    int Deg, Dis; scanf("%d %d", &Deg, &Dis);
    int W = f(Dis);
    string Dirs = g(W, Deg);
    printf("%s %d\n", Dirs.c_str(), W);
    return 0;
}
