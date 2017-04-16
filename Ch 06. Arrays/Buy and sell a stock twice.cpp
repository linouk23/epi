#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price_so_far = INT_MAX;
        int max_total_profit = 0, price;
        int n = (int)prices.size();
        vector<int> best_profits(n);
        for (int index = 0; index < n; ++index) {
            price = prices[index];
            min_price_so_far = min(min_price_so_far, price);
            max_total_profit = max(max_total_profit, price - min_price_so_far);
            best_profits[index] = max_total_profit;
        }
        
        int max_price_so_far = INT_MIN;
        for (int index = n - 1; index > 0; --index) {
            price = prices[index];
            max_price_so_far = max(max_price_so_far, price);
            max_total_profit = max(max_total_profit,
                                   best_profits[index - 1] + max_price_so_far - price);
        }
        return max_total_profit;
    }
};

int main() {
    ios::sync_with_stdio(false);
    
    return 0;
}
