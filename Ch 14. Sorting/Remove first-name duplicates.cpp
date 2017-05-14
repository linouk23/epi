#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct Name {
        bool operator==(const Name& that) const {
            return first_name == that.first_name;
        }
        
        bool operator<(const Name& that) const {
            if (first_name != that.first_name) {
                return first_name < that.first_name;
            }
            return last_name < that.last_name;
        }
        
        string first_name, last_name;
    };
    
    void EliminateDuplicate(vector<Name>& names) {
        sort(names.begin(), names.end());
        // Eliminates all but the first element from every consecutive group
        // of equivalent elements from the range [first, last) and returns a
        // past-the-end iterator for the new logical end of the range.
        names.erase(unique(names.begin(), names.end()), names.end());
    }
};

int main() {
    ios::sync_with_stdio(false);
    return 0;
}
