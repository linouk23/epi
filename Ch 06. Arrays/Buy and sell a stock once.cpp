#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price_so_far = INT_MAX;
        int answer = 0;
        for (int price : prices) {
            min_price_so_far = min(min_price_so_far, price);
            answer = max(answer, price - min_price_so_far);
        }
        return answer;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
