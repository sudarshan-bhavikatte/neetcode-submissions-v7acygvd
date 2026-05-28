class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<int>& stones, int i, int sum, int total) {
        if (memo.find(i) != memo.end()) {
            if (memo[i].find(sum) != memo[i].end()) {
                return memo[i][sum];
            }
        }
        if (i == stones.size()) {
            return abs(sum - (total - sum));
        }

        int skip = dfs(stones, i + 1, sum, total);
        int include = dfs(stones, i + 1, sum + stones[i], total);

        memo[i][sum] = min(skip, include);
        return min(skip, include);
    }

   public:
    // int lastStoneWeightII(vector<int>& stones) {
    //     int total = accumulate(stones.begin(), stones.end(), 0);
    //     int need = (total + 1) / 2;

    //     return dfs(stones, 0, 0, total);
    // }
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(total + 1, 0));

        for (int i = 0; i <= total; i++) {
            dp[n][i] = abs(i - (total - i));
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= total; j++) {
                int skip = dp[i + 1][j];
                int include = INT_MAX;
                if (j + stones[i] <= total) include = dp[i + 1][j + stones[i]];

                dp[i][j] = min(skip, include);
            }
        }

        return dp[0][0];
    }
};
