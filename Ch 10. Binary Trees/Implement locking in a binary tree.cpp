#include "bits/stdc++.h"

using namespace std;

class BinaryTreeNode {
public:
    bool IsLocked() const { return locked_; }
    
    bool Lock() {
        // We cannot lock if any of this node's descendants are locked.
        if (numLockedDescendants_ > 0 || locked_) {
            return false;
        }
        
        // We cannot lock if any of this node's ancestors are locked.
        for (auto iter = parent_; iter != nullptr; iter = iter->parent_) {
            if (iter->locked_) {
                return false;
            }
        }
        
        locked_ = true;
        for (auto iter = parent_; iter != nullptr; iter = iter->parent_) {
            ++iter->numLockedDescendants_;
        }
        return true;
    }
    
    void Unlock() {
        if (locked_) {
            locked_ = false;
            for (auto iter = parent_; iter != nullptr; iter = iter->parent_) {
                --iter->numLockedDescendants_;
            }
        }
    }
    shared_ptr<BinaryTreeNode>& left() { return left_; }
    shared_ptr<BinaryTreeNode>& right() { return right_; }
    shared_ptr<BinaryTreeNode>& parent() { return parent_; }
private:
    shared_ptr<BinaryTreeNode> left_, right_, parent_;
    bool locked_ = false;
    int numLockedDescendants_ = 0;
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
