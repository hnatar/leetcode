class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Let P[i] be the **maximum** profit turnable upto day i.
        // By definition, any further profit must come from the
        // time between day (i-1) and day (i), which is only
        // possible if the stock price rises in that interval.
        int max_profit = 0;
        for(auto i=1; i<prices.size(); i++) {
            max_profit += std::max( prices[i] - prices[i-1], 0 );
        }
        return max_profit;
    }
};