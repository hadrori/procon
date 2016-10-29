#include "bits/stdc++.h"
using namespace std;

typedef pair<int,int> Range;

vector<Range> formatted(vector<Range> ranges) {
    for(auto &r : ranges) {
        r.first = r.first/5*5;
        r.second = (r.second+4)/5*5;
        if(r.second%100 == 60) r.second = r.second/100*100+100;
    }
    sort(begin(ranges),end(ranges));
    ranges.erase(unique(begin(ranges),end(ranges)), end(ranges));
    return ranges;
}
 
vector<Range> merge(vector<Range> ranges) {
    vector<Range> merged_ranges;
    Range cur(0,0);

    for(auto &r : ranges) {
        if(r.first <= cur.second) cur.second = max(cur.second, r.second);
        else {
            if(cur.first < cur.second) merged_ranges.push_back(cur);
            cur = r;
        }
    }
    if(cur.first < cur.second) merged_ranges.push_back(cur);

    return merged_ranges;
}

int main() {
    int n; scanf("%d", &n);
    vector<Range> ranges(n);
    for(int i = 0; i < n; i++) scanf("%d-%d", &ranges[i].first, &ranges[i].second);
    ranges = merge(formatted(ranges));
    for(auto &r : ranges) printf("%04d-%04d\n", r.first, r.second);
    return 0;
}
