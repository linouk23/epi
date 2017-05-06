#include "bits/stdc++.h"

using namespace std;

class MedianFinder {
private:
    priority_queue<int> lower_half; // max-heap
    priority_queue<int, vector<int>, greater<int> > upper_half; // min-heap
public:
    MedianFinder() { }
    
    void addNum(int num) {
        if (lower_half.size() == upper_half.size()) {
            // Add to lower half
            if (!upper_half.empty() && num > upper_half.top()) {
                lower_half.emplace(upper_half.top());
                upper_half.pop();
                upper_half.emplace(num);
            } else {
                lower_half.emplace(num);
            }
        } else {
            // Add to upper half
            if (!lower_half.empty() && num < lower_half.top()) {
                upper_half.emplace(lower_half.top());
                lower_half.pop();
                lower_half.emplace(num);
            } else {
                upper_half.emplace(num);
            }
        }
    }
    
    double findMedian() {
        int size = (int)lower_half.size() + (int)upper_half.size();
        return (size % 2) ? 1.0 * lower_half.top() : (upper_half.top() + lower_half.top()) / 2.0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}