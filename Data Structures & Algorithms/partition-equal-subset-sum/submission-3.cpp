class Solution {
    unordered_map<int, unordered_map<int, int>> memo;
    bool dfs(vector<int>& nums, int i, int target){
        if(memo.find(i) != memo.end()){
            if(memo[i].find(target) != memo[i].end()){
                return memo[i][target];
            }
        }
        if(i == nums.size()){
            return target == 0;
        }

        if(target < 0) return false;
        memo[i][target] = dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);
        return dfs(nums, i + 1, target) || dfs(nums, i + 1, target - nums[i]);
    }
public:
    // bool canPartition(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0);

    //     if(sum % 2 != 0)return false;

    //     int need = sum / 2;

    //     return dfs(nums, 0, need);
    // }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total % 2 != 0)return false;

        int need = total / 2;

        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(need + 1, false));

        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i <= nums.size(); i++){
            for(int j = 1; j <= need; j++){
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] ||
                               dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[nums.size() - 1][need];
    }

    
};
