#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = (int)a.size() - 1;
        int j = (int)b.size() - 1;
        
        string result = "";
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + carry;
            result += to_string(sum % 2);
            carry = sum / 2;
            --i;
            --j;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    Solution solution;
    
    assert(solution.addBinary("11", "11") == "110");
    assert(solution.addBinary("0", "0") == "0");
    
    return 0;
}
