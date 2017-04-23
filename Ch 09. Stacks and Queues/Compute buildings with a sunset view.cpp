#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> st;
        unordered_map<int, int> hashtable;

        for (int num : nums) {
            // Use a stack to keep a decreasing subsequence.
            // Think about [5, 4, 3, 2, 1, 6], [9, 8, 7, 3, 2, 1, 6].
            while (!st.empty() && st.top() < num) {
                hashtable[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> answer;
        for (int num : findNums) {
            answer.emplace_back(hashtable.count(num) ? hashtable[num] : -1);
        }

        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    vector<int> input1 = {4, 1, 2};
    vector<int> input2 = {1, 3, 4, 2};
    vector<int> expected_ans = {-1, 3, -1};
    assert(solution.nextGreaterElement(input1, input2) == expected_ans);

    input1 = {2, 4};
    input2 = {1, 2, 3, 4};
    expected_ans = {3, -1};
    assert(solution.nextGreaterElement(input1, input2) == expected_ans);

    return 0;
}