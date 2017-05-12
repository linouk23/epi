#include "bits/stdc++.h"

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    // Get the value (will always be positive) of the key
    // if the key exists in the cache, otherwise return -1.
    int get(int key) {
        if (!cache_.count(key)) {
            return -1;
        }
        touch(key);
        return cache_[key].first;
    }
    
    // Set or insert the value if the key is not already present.
    // When the cache reached its capacity, it should invalidate the
    // least recently used item before inserting a new item.
    void put(int key, int value) {
        // Update the value and then touch.
        if (cache_.count(key)) {
            cache_[key].first = value;
            touch(key);
            return;
        }
        
        if ((int)queue_.size() == capacity_) {
            int key_to_delete = queue_.back();
            queue_.pop_back();
            cache_.erase(key_to_delete);
        }
        queue_.push_front(key);
        cache_[key] = {value, queue_.begin()};
    }
    
    // Insert node to the front of the linked list
    void touch(int key) {
        auto it_to_delete = cache_[key].second;
        queue_.erase(it_to_delete);
        queue_.push_front(key);
        cache_[key].second = queue_.begin();
    }
private:
    // key -> {value, iterator of LL}
    unordered_map<int, pair<int, list<int>::iterator> > cache_;
    // LL of keys
    list<int> queue_;
    int capacity_;
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
