class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        for(int i = prices.size() - 1; i >= 0; i--){
            for(int buying = 1; buying >= 0; buying--){
                if (buying == 1) {
                    int buy = dp[i + 1][0] - prices[i];
                    int cooldown = dp[i + 1][1];
                    dp[i][1] = max(buy, cooldown);
                } else {
                    int sell = (i + 2 < prices.size()) ? dp[i + 2][1] + prices[i] : prices[i];
                    int cooldown = dp[i + 1][0];
                    dp[i][0] = max(sell, cooldown);
                }
            }
        }

        return dp[0][1];
    }

    int dfs(int i, int buying, vector<int>& prices){
        if(i >= prices.size())return 0;

        int cooldown = dfs(i + 1, buying, prices);
        if(buying){
            int buy = dfs(i + 1, false, prices) - prices[i];
            return max(buy, cooldown);
        } else {
            int sell = dfs(i + 2, true, prices) + prices[i];
            return max(sell, cooldown);
        }
    }

};
