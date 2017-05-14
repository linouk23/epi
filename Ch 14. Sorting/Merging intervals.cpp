#include "bits/stdc++.h"

using namespace std;


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& ins) {
        if (ins.empty()) { return {}; }
        vector<Interval> result;
        sort(ins.begin(), ins.end(), [](Interval a, Interval b) { return a.start < b.start; });
        result.push_back(ins[0]);
        for (const auto &in : ins) {
            if (result.back().end < in.start) {
                result.push_back(in);
            } else {
                result.back().end = max(result.back().end,
                                        in.end);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
