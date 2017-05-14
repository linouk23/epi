#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index_to_write = m + n - 1;
        int le_in_nums_in_fst= m - 1;
        int le_in_nums_in_snd = n - 1;
        
        while(le_in_nums_in_fst >= 0 && le_in_nums_in_snd >= 0) {
            if (nums1[le_in_nums_in_fst] > nums2[le_in_nums_in_snd]) {
                nums1[index_to_write--] = nums1[le_in_nums_in_fst--];
            } else {
                nums1[index_to_write--] = nums2[le_in_nums_in_snd--];
            }
        }
        
        while(le_in_nums_in_fst >= 0) {
            nums1[index_to_write--] = nums1[le_in_nums_in_fst--];
        }
        
        while(le_in_nums_in_snd >= 0) {
            nums1[index_to_write--] = nums2[le_in_nums_in_snd--];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
