#include "bits/stdc++.h"

using namespace std;

class MyQueue {
private:
    stack<int> st1, st2;
public:
    /** Initialize your data structure here. */
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    void reverse() {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (st2.empty()) { reverse(); }
        int val = peek();
        st2.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if (st2.empty()) { reverse(); }
        return st2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
