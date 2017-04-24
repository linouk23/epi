#include "bits/stdc++.h"

using namespace std;

class QueueWithMax {
public:
    void Push(const int& x) {
        entries_.emplace(x);
        // Eliminate dominated elements in candidates_for_max_.
        while (!candidates_for_max_.empty() && candidates_for_max_.back() < x) {
            candidates_for_max_.pop_back();
        }
        candidates_for_max_.emplace_back(x);
    }
    
    int Pop() {
        if (!entries_.empty()) {
            int result = entries_.front();
            if (result == candidates_for_max_.front()) {
                candidates_for_max_.pop_front();
            }
            entries_.pop();
            return result;
        }
        throw length_error("empty queue");
    }
    
    const int& Max() const {
        if (!candidates_for_max_.empty()) {
            return candidates_for_max_.front();
        }
        throw length_error("empty queue");
    }
    
    int& Front() { return entries_.front(); }
    
private:
    queue<int> entries_;
    deque<int> candidates_for_max_;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
