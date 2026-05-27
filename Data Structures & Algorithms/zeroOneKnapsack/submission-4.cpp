class Solution {
    vector<vector<int>> memo;

    int dfs(vector<int>& profit, vector<int>& weight, int i, int capacity){
        if(i == profit.size()){
            return 0;
        }
        if(memo[i][capacity] != -1)return memo[i][capacity];

        int maxProfit = dfs(profit, weight, i + 1, capacity);

        int newCap = capacity - weight[i];

        if(newCap >= 0){
            int include = profit[i] + dfs(profit, weight, i + 1, newCap);
            maxProfit = max(maxProfit, include); 
        }
        memo[i][capacity] = maxProfit;
        return maxProfit;
    }
public:
    // int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
    //     memo.assign(weight.size(), vector<int>(capacity + 1, -1));
    //     return dfs(profit, weight, 0, capacity);
    // }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<vector<int>> dp(profit.size(), vector<int>(capacity + 1, 0));

        for(int i = 0; i < profit.size(); i++){
            int w = weight[i];
            for(int j = 0; j < capacity + 1; j++){

                if(w <= j){
                    if(i == 0) dp[i][j] = profit[i];
                    else dp[i][j] = max(dp[i - 1][j], profit[i] + dp[i - 1][j - w]);
                }
                else{
                    if(i == 0) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[profit.size() - 1][capacity];
    }
};
