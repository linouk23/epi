#include "bits/stdc++.h"

using namespace std;

class Queue {
public:
    explicit Queue(size_t capacity) : entries(capacity) {}
    
    void Push(int x) {
        if (num_queue_elements == entries.size()) {  // Needs to resize.
            // Makes the queue elements appear consecutively.
            rotate(entries.begin(), entries.begin() + head, entries.end());
            
            // 1 2 3 4 5 6 7 8 9
            // head = 3
            // 4 5 6 7 8 9 1 2 3
            
            
            head = 0, tail = num_queue_elements;
            entries.resize(entries.size() * scale_factor);
        }
        
        entries[tail] = x;
        tail = (tail + 1) % entries.size(), ++num_queue_elements;
    }
    
    int Pop() {
        --num_queue_elements;
        int fst = entries[head];
        head = (head + 1) % entries.size();
        return fst;
    }
    
    size_t size() const { return num_queue_elements; }
    
private:
    const int scale_factor = 2;
    size_t head = 0, tail = 0, num_queue_elements = 0;
    vector<int> entries;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
