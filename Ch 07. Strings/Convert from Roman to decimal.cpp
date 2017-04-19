#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashtable = {
           { 'I' , 1 },
           { 'V' , 5 },
           { 'X' , 10 },
           { 'L' , 50 },
           { 'C' , 100 },
           { 'D' , 500 },
           { 'M' , 1000 } 
        };

        int sum = hashtable[s.back()];
        for (int index = s.length() - 2; index >= 0; --index) {
            if (hashtable[s[index]] < hashtable[s[index + 1]]) {
                sum -= hashtable[s[index]];
            } else {
                sum += hashtable[s[index]];
            }
        }
        
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);

    Solution solution;

    assert(solution.romanToInt("DCXXI") == 621);
    assert(solution.romanToInt("XXI") == 21);
    assert(solution.romanToInt("IX") == 9);
    assert(solution.romanToInt("III") == 3);

    return 0;
}
