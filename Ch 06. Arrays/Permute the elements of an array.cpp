#include "bits/stdc++.h"

using namespace std;

void ApplyPermutation(vector<int> &perm, vector<int> &vec) {
    int n = (int)vec.size();
    for (int index = 0; index < n; ++index) {
        int next = index;
        while (perm[next] >= 0) {
            swap(vec[index], vec[perm[next]]);
            int temp = perm[next];

            perm[next] -= n;
            next = temp;
        }
    }
    
    for_each(begin(perm), end(perm), [&perm](int& x) { x += (int)perm.size(); });
}

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}