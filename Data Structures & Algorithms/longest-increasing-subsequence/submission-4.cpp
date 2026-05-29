class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    int dfs(vector<int>& nums, int i, int j) {
        if (memo.find(i) != memo.end()) {
            if (memo[i].find(j) != memo[i].end()) {
                return memo[i][j];
            }
        }
        if (i == nums.size()) return 0;

        int res = dfs(nums, i + 1, j);

        if (j == -1 || nums[j] < nums[i]) {
            res = max(res, 1 + dfs(nums, i + 1, i));
        }
        memo[i][j] = res;
        return res;
    }

   public:
    // int lengthOfLIS(vector<int>& nums) {
    //     return dfs(nums, 0, -1);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = -1; j < n; j++) {
                int skip = dp[i + 1][j + 1];  

                int take = 0;
                if (j == -1 || nums[j] < nums[i])
                    take = 1 + dp[i + 1][i + 1];  

                dp[i][j + 1] = max(skip, take);
            }
        }

        return dp[0][0];
    }
};
