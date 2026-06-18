class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_date = 0;
        int sell_date = 1;
        int max_profit = 0;

        while (sell_date < prices.size()) {
            if (prices[sell_date] - prices[buy_date] < 0) {
                buy_date = sell_date;
                sell_date = buy_date + 1;
                continue;
            }
            else {
                if (prices[sell_date] - prices[buy_date] > max_profit) {
                    max_profit = prices[sell_date] - prices[buy_date];
                }
                sell_date ++;
            }
        }
        return max_profit;
    }
};
