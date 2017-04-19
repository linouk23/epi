#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ReplaceAndRemove(int size, string s) {
        int write_id = 0, a_count = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] != 'b') {
                s[write_id++] = s[i];
            }
            if (s[i] == 'a') {
                ++a_count;
            }
        }
        
        int cur_id = write_id - 1;
        write_id = write_id + a_count - 1;
        int result = write_id + 1;
        while (cur_id >= 0) {
            if (s[cur_id] == 'a') {
                s[write_id--] = 'd';
                s[write_id--] = 'd';
            } else {
                s[write_id--] = s[cur_id];
            }
            --cur_id;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
