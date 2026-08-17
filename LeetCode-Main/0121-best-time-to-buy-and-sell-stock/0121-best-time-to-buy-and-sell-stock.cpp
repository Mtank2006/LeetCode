class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int buy = prices[0];
        int profit = 0;
        for (size_t i = 1; i < size ; ++i) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};


