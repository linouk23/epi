#include "bits/stdc++.h"

using namespace std;

struct Point {
    bool operator<(const Point& that) const {
        return Distance() < that.Distance();
    }
    
    double Distance() const { return sqrt(x * x + y * y); }
    
    double x, y;
};

class Solution {
public:
    vector<Point> FindClosestKPoints(int k) {
        priority_queue<Point, vector<Point>> max_heap;
        
        while (hasNextPoint()) {
            Point p = getNextPoint();
            if (max_heap.size() < k + 1) {
                max_heap.emplace(p);
            } else if (!(max_heap.top() < p)) {
                max_heap.pop();
                max_heap.emplace(p);
            }
        }
        
        vector<Point> result;
        while (!max_heap.empty()) {
            result.emplace_back(max_heap.top());
            max_heap.pop();
        }
        return {result.rbegin(), result.rend()};
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
