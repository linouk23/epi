#include "bits/stdc++.h"

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> changes;
    for (auto interval : intervals) {
        changes[interval.start] += 1;
        changes[interval.end] -= 1;
    }
    int rooms = 0, maxrooms = 0;
    for (auto change : changes)
        rooms += change.second;
        maxrooms = max(maxrooms, rooms);
    return maxrooms;
}

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
