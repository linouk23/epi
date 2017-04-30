#include "bits/stdc++.h"

using namespace std;

class Stack {
public:
    void Push(int x) { max_heap_.emplace(x, timestamp_++); }
    
    int Pop() {
        if (max_heap_.empty()) { throw length_error("empty stack"); }
        int val = max_heap_.top().value;
        max_heap_.pop();
        return val;
    }
    
    int Top() const { return max_heap_.top().value; }
    
private:
    int timestamp_ = 0;
    
    struct StackVertex {
        int value, push_time;
        
        bool operator<(const StackVertex& that) const {
            return push_time < that.push_time;
        }
    };
    priority_queue<StackVertex, vector<StackVertex>> max_heap_;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
