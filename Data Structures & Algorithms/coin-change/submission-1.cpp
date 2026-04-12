class Solution {
private:
    vector<vector<int>> dp;

    int dfs(int i, int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (i == coins.size() || amount < 0) return 1e9;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int take = 1 + dfs(i, amount - coins[i], coins);
        int skip = dfs(i + 1, amount, coins);

        return dp[i][amount] = min(take, skip);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<vector<int>>(coins.size(),
                                 vector<int>(amount + 1, -1));

        int res = dfs(0, amount, coins);
        return res >= 1e9 ? -1 : res;
    }
};
