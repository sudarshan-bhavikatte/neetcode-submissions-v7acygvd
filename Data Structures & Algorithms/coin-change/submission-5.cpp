class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<int>& coins, int i, int amount){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(amount) != memo[i].end()){
                return memo[i][amount];
            }
        }
        if(amount == 0) return 0;
        if(i == coins.size()){
            return INT_MAX;
        }

        int skip = dfs(coins, i + 1, amount);

        int include = INT_MAX;

        if(amount - coins[i] >= 0){
            int sub = dfs(coins, i, amount - coins[i]);
            if(sub != INT_MAX)include = 1 + sub;
        }

        memo[i][amount] = min(skip, include);

        return min(skip, include);
    }
public:
    // int coinChange(vector<int>& coins, int amount) {
    //     int res = dfs(coins, 0, amount);
    //     return res == INT_MAX ? -1 : res;
    // }

    int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
    for(int i = 0; i <= n; i++) dp[i][0] = 0;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= amount; j++){
            int skip = dp[i + 1][j];

            int include = INT_MAX;
            if(j - coins[i] >= 0 && dp[i][j - coins[i]] != INT_MAX)
                include = 1 + dp[i][j - coins[i]];

            dp[i][j] = min(skip, include);
        }
    }

    return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
}
};
