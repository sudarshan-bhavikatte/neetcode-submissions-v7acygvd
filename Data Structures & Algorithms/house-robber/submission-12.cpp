class Solution {
    unordered_map<int, int> memo;
    int dfs(vector<int>& nums, int i){
        if(memo.count(i))return memo[i];
        if(i >= nums.size())return 0;

        memo[i] = max(nums[i] + dfs(nums, i + 2), dfs(nums, i + 1)); 
        return memo[i];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);

        for(int i = nums.size() - 1; i >= 0; i--){
            int inc = nums[i];
            if(i + 2 < dp.size()){
                inc += dp[i + 2];
            }    
            int skip = dp[i + 1];

            dp[i] = max(inc, skip);
        }
        return dp[0];
    }
};
