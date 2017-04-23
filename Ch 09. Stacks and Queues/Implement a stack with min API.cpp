#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
    stack<int> min_st;
    stack<int> st;
public:
    MinStack() {}
    
    void push(int x) {
        st.push(x);

        if (min_st.empty() || min_st.top() > x) {
            min_st.push(x);
        } else {
            min_st.push(min_st.top());
        }
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

int main() {
    ios::sync_with_stdio(false);

    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3);
    minStack.pop();
    assert(minStack.top() == 0);
    assert(minStack.getMin() == -2);

    return 0;
}
