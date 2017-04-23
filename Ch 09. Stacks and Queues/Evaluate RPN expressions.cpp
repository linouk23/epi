#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> ops = {"+", "-", "*", "/"};
        stack<int> st;
        for (const auto & token : tokens) {
            if (ops.count(token)) {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                switch (token.front()) {
                    case '+':
                        st.emplace(op2 + op1);
                        break;
                    case '-':
                        st.emplace(op2 - op1);
                        break;
                    case '*':
                        st.emplace(op2 * op1);
                        break;
                    case '/':
                        st.emplace(op2 / op1);
                        break;
                }
            } else {
                st.emplace(stoi(token));
            }
        }
        return st.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
